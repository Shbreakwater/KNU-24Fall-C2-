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
    double a, b;   // 적분 구간
    int max_power; // 최대 2^n에서 n의 값

    // 사용자 입력
    printf("적분할 시작 값을 입력하세요: ");
    scanf_s("%lf", &a);
    printf("적분할 끝 값을 입력하세요: ");
    scanf_s("%lf", &b);
    printf("실행할 최대 구간을 입력하세요 (2^n): ");
    scanf_s("%d", &max_power);

    // n = 2^k로 구간을 늘려가며 계산
    for (int k = 0; k <= max_power; k++) {
        int n = 1 << k; // n = 2^k
        double result = trapezoidal_integral(a, b, n);
        printf("구간 %d 적분 결과: %.6lf\n", n, result);
    }

    return 0;
}