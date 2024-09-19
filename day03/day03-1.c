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
    printf("������ �Է��Ͻÿ�: ");
    scanf_s("%d", &num);

    if (is_prime(num)) {
        printf("%d�� �Ҽ��̴�. �׷��Ƿ� 1.\n", num);
    }
    else {
        printf("%d�� �Ҽ��� �ƴϴ�.�׷��Ƿ� 0.\n", num);
    }

    return 0;
}