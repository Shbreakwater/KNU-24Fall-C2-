#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void fillRandom(void* array) {
    srand(time(0));
    for (int i = 0; i < SIZE * SIZE; i++) {
        *((int*)array + i) = rand() % 20 + 1;
    }
}

void printArray(void* array) {
    printf("배열 출력:\n");
    for (int i = 0; i < SIZE * SIZE; i++) {
        printf("%2d ", *((int*)array + i));
        if ((i + 1) % SIZE == 0) printf("\n");
    }
}

void movePointer(void* array) {
    int x = 0, y = 0;
    int value;

    while (1) {
        int * ptr = (int*)array + x * SIZE + y;
        value = *ptr;
        printf("현재 위치: (%d, %d), 배열의 값: %d\n", x, y, value);
        int newX = x;
        int newY = y + value;
        if (newY >= SIZE) {
            newX += newY / SIZE;
            newY = newY % SIZE;
        }

        if (newX < SIZE && newY < SIZE) {
            x = newX;
            y = newY;
        }
        else {
            break;
        }
    }
    int* finalPtr = (int*)array + x * SIZE + y;
    printf("더 이상 이동할 수 없습니다.\n");
    printf("종료 위치: (%d, %d), 배열의 값: %d\n", x, y, *finalPtr);
}


int main() {
    int array[SIZE][SIZE];

    fillRandom(array); 
    printArray(array);

    movePointer(array);

    return 0;
}