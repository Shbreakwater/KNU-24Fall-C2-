#include <stdio.h>

int is_prime(int num) {
    
    if (num <= 1) {
        return 0;
    }

    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int num;
    printf("정수를 입력하시오: ");
    scanf_s("%d", &num);

    if (is_prime(num)) {
        printf("%d는 소수이다. 그러므로 1.\n", num);
    }
    else {
        printf("%d는 소수가 아니다.그러므로 0.\n", num);
    }

    return 0;
}