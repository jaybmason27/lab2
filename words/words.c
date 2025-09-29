#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Process file and print words one per line
void process_file(FILE *fp) {
    int c;
    char buffer[1024];
    int idx = 0;

    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c)) {
            // Add character to current word
            if (idx < sizeof(buffer) - 1) {
                buffer[idx++] = (char)c;
            }
        } else {
            // End of a word
            if (idx > 0) {
                buffer[idx] = '\0';
                printf("%s\n", buffer);
                idx = 0;
            }
        }
    }

    // Catch trailing word if file ends on letter
    if (idx > 0) {
        buffer[idx] = '\0';
        printf("%s\n", buffer);
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        // No filenames: read from stdin
        process_file(stdin);
    } else {
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "-") == 0) {
                process_file(stdin);
            } else {
                FILE *fp = fopen(argv[i], "r");
                if (fp == NULL) {
                    fprintf(stderr, "words: cannot open file %s\n", argv[i]);
                    return 1;
                }
                process_file(fp);
                fclose(fp);
            }
        }
    }
    return 0;
}
