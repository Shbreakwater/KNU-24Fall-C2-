#include <stdio.h>

double function(double x) {
    return x * x + 1;
}

double trapezoidal_integral(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;

    sum += function(a) / 2.0;
    sum += function(b) / 2.0;

    for (int i = 1; i < n; i++) {
        sum += function(a + i * h);
    }

    return sum * h;
}

int main() {
    double a, b;   // ���� ����
    int max_power; // �ִ� 2^n���� n�� ��

    // ����� �Է�
    printf("������ ���� ���� �Է��ϼ���: ");
    scanf_s("%lf", &a);
    printf("������ �� ���� �Է��ϼ���: ");
    scanf_s("%lf", &b);
    printf("������ �ִ� ������ �Է��ϼ��� (2^n): ");
    scanf_s("%d", &max_power);

    // n = 2^k�� ������ �÷����� ���
    for (int k = 0; k <= max_power; k++) {
        int n = 1 << k; // n = 2^k
        double result = trapezoidal_integral(a, b, n);
        printf("���� %d ���� ���: %.6lf\n", n, result);
    }

    return 0;
}