#include <stdio.h>

int main() {
    int n, i, j, k;

    printf("�Ƕ�̵� �� ���� �Է��ϼ���: ");
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