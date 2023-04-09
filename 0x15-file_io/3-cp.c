#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    FILE *file_from, *file_to;
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    if (argc != 3) {
        fprintf(stderr, "Usage: cp file_from file_to\n");
        exit(97);
    }

    file_from = fopen(argv[1], "rb");
    if (file_from == NULL) {
        fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    file_to = fopen(argv[2], "wb");
    if (file_to == NULL) {
        fprintf(stderr, "Error: Can't write to %s\n", argv[2]);
        exit(99);
    }

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file_from)) > 0) {
        if (fwrite(buffer, 1, bytes_read, file_to) != bytes_read) {
            fprintf(stderr, "Error: Can't write to %s\n", argv[2]);
            fclose(file_from);
            fclose(file_to);
            exit(99);
        }
    }

    fclose(file_from);
    fclose(file_to);
    return 0;
}

