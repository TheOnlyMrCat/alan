#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Not enough arguments");
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];

    FILE *file = fopen(filename, "r");

    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    int c;
    int lineno;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            ++lineno;
            continue;
        }
    }

    if (ferror(file)) {
        puts("An error occurred when reading");
    }

    fclose(file);

    return EXIT_SUCCESS;
}