#include <stdio.h>


int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    int number;
    printf("���ڸ� �Է��Ͻÿ�: ");
    scanf_s("%d", &number);
    printf("%d! = %d\n", number, factorial(number));

    return 0;
}
