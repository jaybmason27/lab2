/*
 * histo.c     Jay Mason     October 2, 2025
 *
 * This program reads a series of positive integers from stdin
 * and prints a histogram with 16 bins. Each bin holds a count
 * of numbers within a specific range. The bin size begins at 1
 * and doubles dynamically whenever a number is encountered that
 * exceeds the current histogram range.
 *
 * Behavior:
 *   - Input is read as integers from stdin.
 *   - Negative integers are ignored.
 *   - Bin count is fixed at 16.
 *   - Bin size and range double when needed to accommodate values.
 *   - Histogram is printed at EOF, showing ranges and counts.
 *
 * Exit codes:
 *   - Always exits with 0 (no error conditions expected).
 *
 * Usage:
 *   ./histo < inputfile
 */

#include <stdio.h>

#define BINS 16

/* ********************************************
 * main()
 *
 * Reads integers from stdin, assigns them to bins,
 * dynamically expands bin size as necessary, and
 * prints a histogram of observed values.
 *
 * Returns:
 *   Always 0 (success).
 *
 * Code:
 *   - Ignores negative integers.
 *   - Doubles bin size/range when needed.
 *   - Prints updated header when bin size changes.
 * ******************************************** */
int main(void) {
    int bins[BINS] = {0};
    int bin_size = 1;
    int range = BINS * bin_size;

    printf("%d bins of size %d for range [0,%d)\n", BINS, bin_size, range);

    int n;
    while (scanf("%d", &n) == 1) {
        if (n < 0) continue;

        // Expand until n fits
        while (n >= range) {
            bin_size *= 2;
            range = BINS * bin_size;
            // compress bins
            for (int i = 0; i < BINS / 2; i++) {
                bins[i] = bins[2*i] + bins[2*i + 1];
            }
            for (int i = BINS / 2; i < BINS; i++) {
                bins[i] = 0;
            }
            printf("%d bins of size %d for range [0,%d)\n", BINS, bin_size, range);
        }

        int index = n / bin_size;
        bins[index]++;
    }

    // print histogram
    for (int i = 0; i < BINS; i++) {
        int low = i * bin_size;
        int high = (i+1) * bin_size - 1;
        printf("[%3d:%3d] ", low, high);
        for (int j = 0; j < bins[i]; j++) {
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}
