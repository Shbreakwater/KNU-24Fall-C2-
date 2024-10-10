#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    long long int i, iterations = 1000000000;
    long long int inside_circle = 0;
    double x, y, distance, pi_estimate;
    int progress, squares_to_display;

    srand(time(NULL));

    for (i = 1; i <= iterations; i++) {
        
        x = (double)rand() / (double)RAND_MAX;
        y = (double)rand() / (double)RAND_MAX;

        distance = sqrt(x * x + y * y);
        if (distance <= 1.0) {
            inside_circle++;
        }
        if (i % 10000000 == 0) {
            pi_estimate = 4.0 * inside_circle / i;
            progress = (i * 100) / iterations;
            squares_to_display = progress / 5;

            printf("%2.d%% 진행.. 원주율: %.6f ", progress, pi_estimate);

            
            for (int j = 0; j < squares_to_display; j++) {
                printf("$");
            }
            for (int j = squares_to_display; j < 50; j++) {
                printf(" ");
            }

            printf("\n");
        }
    }

    pi_estimate = 4.0 * inside_circle / iterations;
    printf("원주율: % .6f\n", pi_estimate);

    return 0;
}
