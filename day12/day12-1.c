#include <stdio.h>
#include <stdlib.h>

int solution(int topping[], int toppingSize) {
    int left[10001] = { 0 };
    int right[10001] = { 0 };
    int left_count = 0, right_count = 0;
    int fair_cut_count = 0;

    for (int i = 0; i < toppingSize; i++) {
        if (right[topping[i]] == 0) {
            right_count++;
        }
        right[topping[i]]++;
    }

    for (int i = 0; i < toppingSize - 1; i++) {
        if (left[topping[i]] == 0) {
            left_count++;
        }
        left[topping[i]]++;

        right[topping[i]]--;
        if (right[topping[i]] == 0) {
            right_count--;
        }

        if (left_count == right_count) {
            fair_cut_count++;
        }
    }

    return fair_cut_count;
}

int main() {
    int topping1[] = { 1, 2, 1, 3, 1, 4, 1, 2 };
    int size1 = sizeof(topping1) / sizeof(topping1[0]);
    printf("%d\n", solution(topping1, size1));

    int topping2[] = { 1, 2, 3, 1, 4 };
    int size2 = sizeof(topping2) / sizeof(topping2[0]);
    printf("%d\n", solution(topping2, size2));

    return 0;
}
