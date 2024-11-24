#include <stdio.h>
#include <math.h>

double function(double x) {
    return (- log10(1 / x)) + sin(x);
}

// ���б������� ����� ���� ���
double trapezoidal_integral(double a, double b, long n) {
    double h = (b - a) / (double)n; // ���� ����
    double sum = 0.0;       // �հ� ����

    
    for (long i = 0; i < n; i++) {
        sum += h*function(a + i * h );
        
    }

    // ��� ��ȯ
    return sum;
}

int main() {
    double a, b;     // ���� ����
    long max_power;  // �ִ� 2^n���� n�� ��

    // ����� �Է�
    printf("������ ���� ���� �Է��ϼ���: ");
    scanf_s("%lf", &a);
    printf("������ �� ���� �Է��ϼ���: ");
    scanf_s("%lf", &b);
    printf("������ �ִ� ������ �Է��ϼ��� (2^n): ");
    scanf_s("%ld", &max_power);

    // n = 2^k�� ������ �÷����� ���
    for (long k = 0; k <= max_power; k++) {
        long n = pow(2, k);
        double result = trapezoidal_integral(a, b, n);
        printf("���� %ld ���� ���: %.6lf\n", n, result);
    }

    return 0;
}

