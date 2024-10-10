#include <stdio.h>

int main() {
    int n, i, j, k;

    printf("피라미드 층 수를 입력하세요: ");
    scanf_s("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = i; j < n; j++) {
            printf(" ");
        }
        for (k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}