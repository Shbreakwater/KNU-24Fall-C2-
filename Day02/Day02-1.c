#include <stdio.h>

int main() {
    double num1, num2;
    char op;

    printf("첫 번째 숫자를 입력하세요: ");
    scanf_s("%lf", &num1);

    printf("연산자를 입력하세요 (+, -, *, /): ");
    scanf_s(" %c", &op);

    printf("두 번째 숫자를 입력하세요: ");
    scanf_s("%lf", &num2);

    switch (op) {
    case '+':
        printf("결과: %.2lf\n", num1 + num2);
        break;
    case '-':
        printf("결과: %.2lf\n", num1 - num2);
        break;
    case '*':
        printf("결과: %.2lf\n", num1 * num2);
        break;
    case '/':
        if (num2 != 0)
            printf("결과: %.2lf\n", num1 / num2);
        else
            printf("0으로 나눌 수 없습니다.\n");
        break;
    default:
        printf("유효하지 않은 연산자입니다.\n");
    }

    return 0;
}