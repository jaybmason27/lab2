/*
 * chill.c     Jay Mason     October 2025
 *
 * This program calculates the wind chill factor given a temperature (F)
 * and wind velocity (mph). It supports three modes:
 *   - No arguments: prints a table of wind chills for temps -10..40 by 10,
 *     and wind speeds 5..15 by 5.
 *   - One argument: interprets as temperature, prints wind chill table for
 *     that temperature and wind speeds 5..15 by 5.
 *   - Two arguments: interprets as temperature and velocity, prints wind chill
 *     for that specific case.
 *
 * Input validation:
 *   - Temperature must be < 50 F and > -99 F
 *   - Wind velocity must be ≥ 0.5 mph
 *
 * Exit codes:
 *   - 0 for success
 *   - 1 for invalid arguments
 *
 * Usage:
 *   ./chill [temperature] [velocity]
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Formula
double wind_chill(double T, double V) {
    return 35.74 + 0.6215 * T - 35.75 * pow(V, 0.16) + 0.4275 * T * pow(V, 0.16);
}

/* ********************************************
 * main()
 *
 * Handle program arguments and print wind chill output
 * according to the number of arguments provided.
 *
 * Arguments:
 *   argc - number of command-line arguments
 *   argv - array of command-line arguments
 *
 * Returns:
 *   0 if successful, non-zero on error.
 * ******************************************** */
int main(int argc, char *argv[]) {
    if (argc == 1) {
        // Print table for temps -10..40 by 10 and winds 5..15 by 5
        printf("  Temp   Wind  Chill\n");
        printf(" -----  -----  -----\n");
        for (double T = -10.0; T <= 40.0; T += 10.0) {
            for (double V = 5.0; V <= 15.0; V += 5.0) {
                printf("%6.1f %6.1f %6.1f\n", T, V, wind_chill(T, V));
            }
            printf("\n");
        }
    }
    else if (argc == 2) {
        double T = atof(argv[1]);
        if (T >= 50.0 || T <= -99.0) {
            fprintf(stderr, "./chill: Temperature must be less than or equal to 50.0 degrees Fahrenheit\n");
            return 1;
        }
        printf("  Temp   Wind  Chill\n");
        printf(" -----  -----  -----\n");
        for (double V = 5.0; V <= 15.0; V += 5.0) {
            printf("%6.1f %6.1f %6.1f\n", T, V, wind_chill(T, V));
        }
    }
    else if (argc == 3) {
        double T = atof(argv[1]);
        double V = atof(argv[2]);
        if (T >= 50.0 || T <= -99.0) {
            fprintf(stderr, "./chill: Temperature must be less than or equal to 50.0 degrees Fahrenheit\n");
            return 1;
        }
        if (V < 0.5) {
            fprintf(stderr, "./chill: Wind velocity must be greater than or equal to 0.5 MPH\n");
            return 1;
        }
        printf("  Temp   Wind  Chill\n");
        printf(" -----  -----  -----\n");
        printf("%6.1f %6.1f %6.1f\n", T, V, wind_chill(T, V));
    }
    else {
        fprintf(stderr, "Usage: ./chill [temperature] [velocity]\n");
        return 1;
    }

    return 0;
}
