/*
 * words.c     Jay Mason     October 2, 2025
 *
 * This program breaks input into words, printing one word per line.
 * Input can be from stdin or from files listed as command-line arguments.
 *
 * Behavior:
 *   - No arguments: read from stdin.
 *   - One or more filenames: read each file in sequence.
 *   - Special filename "-" indicates reading from stdin at that point.
 *
 * A word is defined as a maximal sequence of alphabetic characters
 *
 * Errors:
 *   - If a file cannot be opened, an error message is written to stderr,
 *     and the program exits with status 1.
 *
 * Exit codes:
 *   - 0 for success
 *   - 1 for failure to open file
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


/* ********************************************
 * process_file()
 *
 * Reads characters from the given file pointer.
 * Collects alphabetic sequences into words and
 * prints each word on its own line.
 *
 * ******************************************** */
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

/* ********************************************
 * main()
 *
 * determines input source(s) and
 * calls process_file() accordingly.
 *
 * ******************************************** */
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
