#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initializeAndPrintArray(int (*array)[10]) {
    srand(time(0));
    printf("�迭 ���:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            array[i][j] = rand() % 20 + 1;
            printf("%2d ", array[i][j]);
        }
        printf("\n");
    }
}

int move(int (*array)[10], int *x, int *y) {
    int value = *(*(array + *x) + *y);
    printf("���� ��ġ: (%d, %d), �迭�� ��: %d\n", *x, *y, value);

    int newX = *x;
    int newY = *y + value;

    if (newY >= 10) {
        newX += newY / 10;
        newY = newY % 10;
    }

    if (newX < 10 && newY < 10) {
        *x = newX;
        *y = newY;
        return 1;
    }
    return 0;
}

void printFinalPosition(int x, int y, int value) {
    printf("�� �̻� �̵��� �� �����ϴ�.\n");
    printf("���� ��ġ: (%d, %d), �迭�� ��: %d\n", x, y, value);
}

int main() {
    int array[10][10];
    int x = 0, y = 0;

    initializeAndPrintArray(array);

    while (move(array, &x, &y));

    printFinalPosition(x, y, array[x][y]);

    return 0;
}
