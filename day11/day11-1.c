#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double fan, root1, root2;

    printf("이차방정식의 계수 a, b, c를 입력하세요 (ax^2 + bx + c = 0): ");
    scanf_s("%lf %lf %lf", &a, &b, &c);

    fan = b * b - 4 * a * c;

    if (fan > 0) {
        root1 = (-b + sqrt(fan)) / (2 * a);
        root2 = (-b - sqrt(fan)) / (2 * a);
        printf("근: %.2lf, %.2lf\n", root1, root2);
    }
    else if (fan == 0) {
        root1 = -b / (2 * a);
        printf("중근: %.2lf\n", root1);
    }
    else {
        printf("실근이 없습니다.\n");
    }

    return 0;
}
