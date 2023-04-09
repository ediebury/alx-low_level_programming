#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <ELF file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    unsigned char e_ident[EI_NIDENT];
    if (read(fd, e_ident, EI_NIDENT) != EI_NIDENT)
    {
        perror("read");
        exit(EXIT_FAILURE);
    }

    check_elf(e_ident);
    print_magic(e_ident);
    print_class(e_ident);
    print_data(e_ident);
    print_version(e_ident);
    print_abi(e_ident);
    print_osabi(e_ident);

    Elf32_Ehdr e_hdr;
    if (lseek(fd, 0, SEEK_SET) < 0 ||
        read(fd, &e_hdr, sizeof(e_hdr)) != sizeof(e_hdr))
    {
        perror("read");
        exit(EXIT_FAILURE);
    }

    print_type(e_hdr.e_type, e_ident);
    print_entry(e_hdr.e_entry, e_ident);

    close_elf(fd);

    return 0;
}

void check_elf(unsigned char *e_ident)
{
    if (e_ident[EI_MAG0] != ELFMAG0 ||
        e_ident[EI_MAG1] != ELFMAG1 ||
        e_ident[EI_MAG2] != ELFMAG2 ||
        e_ident[EI_MAG3] != ELFMAG3)
    {
        fprintf(stderr, "Error: Not an ELF file\n");
        exit(EXIT_FAILURE);
    }
}

void print_magic(unsigned char *e_ident)
{
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++)
        printf("%02x ", e_ident[i]);
    printf("\n");
}

void print_class(unsigned char *e_ident)
{
    printf("  Class:   ");
    switch (e_ident[EI_CLASS])
    {
    case ELFCLASSNONE:
        printf("none\n");
        break;
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_CLASS]);
    }
}

void print_data(unsigned char *e_ident)
{
    printf("  Data:    ");
    switch (e_ident[EI_DATA])
    {
    case ELFDATANONE:
        printf("none\n");
        break;
    case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
    default

