#include <stdio.h>

#define BINS 16

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
