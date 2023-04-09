#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_error - Prints an error message to stderr and exits with code 98.
 * @msg: The error message to print.
 */
void print_error(char *msg)
{
    dprintf(STDERR_FILENO, "%s\n", msg);
    exit(98);
}

/**
 * print_elf_header - Prints information from an ELF header.
 * @header: A pointer to the ELF header.
 */
void print_elf_header(Elf64_Ehdr *header)
{
    printf("Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++)
        printf("%02x ", header->e_ident[i]);
    printf("\n");

    printf("Class:                             %s\n", (header->e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");
    printf("Data:                              %s\n", (header->e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" : "2's complement, big endian");
    printf("Version:                           %d%s\n", header->e_ident[EI_VERSION], (header->e_ident[EI_VERSION] == EV_CURRENT) ? " (current)" : "");
    printf("OS/ABI:                            %d\n", header->e_ident[EI_OSABI]);
    printf("ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);

    printf("Type:                              %d", header->e_type);
    switch (header->e_type) {
        case ET_NONE:        printf(" (NONE)");        break;
        case ET_REL:         printf(" (REL)");         break;
        case ET_EXEC:        printf(" (EXEC)");        break;
        case ET_DYN:         printf(" (DYN)");         break;
        case ET_CORE:        printf(" (CORE)");        break;
        default:             printf(" (UNKNOWN)");     break;
    }
    printf("\n");

    printf("Entry point address:               %lx\n", header->e_entry);
}

/**
 * main - Displays information from the ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
    int fd;
    Elf64_Ehdr header;

    if (argc != 2)
        print_error("Usage: elf_header elf_filename");

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        print_error("Error: Cannot read file");

    if (read(fd, &header, sizeof(header)) != sizeof(header))
        print_error("Error: Cannot read ELF header");

    if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 || header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
        print_error("Error: Not an ELF file");

    print_elf_header(&header);

    close(fd);

    return 0;
}

