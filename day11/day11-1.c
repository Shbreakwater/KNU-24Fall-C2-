#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double fan, root1, root2;

    printf("������������ ��� a, b, c�� �Է��ϼ��� (ax^2 + bx + c = 0): ");
    scanf_s("%lf %lf %lf", &a, &b, &c);

    fan = b * b - 4 * a * c;

    if (fan > 0) {
        root1 = (-b + sqrt(fan)) / (2 * a);
        root2 = (-b - sqrt(fan)) / (2 * a);
        printf("��: %.2lf, %.2lf\n", root1, root2);
    }
    else if (fan == 0) {
        root1 = -b / (2 * a);
        printf("�߱�: %.2lf\n", root1);
    }
    else {
        printf("�Ǳ��� �����ϴ�.\n");
    }

    return 0;
}
