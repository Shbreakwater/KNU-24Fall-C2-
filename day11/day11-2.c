#include <stdio.h>
#include <math.h>

double function(double x) {
    return (- log10(1 / x)) + sin(x);
}

// 구분구적법을 사용한 적분 계산
double trapezoidal_integral(double a, double b, long n) {
    double h = (b - a) / (double)n; // 구간 간격
    double sum = 0.0;       // 합계 변수

    
    for (long i = 0; i < n; i++) {
        sum += h*function(a + i * h );
        
    }

    // 결과 반환
    return sum;
}

int main() {
    double a, b;     // 적분 구간
    long max_power;  // 최대 2^n에서 n의 값

    // 사용자 입력
    printf("적분할 시작 값을 입력하세요: ");
    scanf_s("%lf", &a);
    printf("적분할 끝 값을 입력하세요: ");
    scanf_s("%lf", &b);
    printf("실행할 최대 구간을 입력하세요 (2^n): ");
    scanf_s("%ld", &max_power);

    // n = 2^k로 구간을 늘려가며 계산
    for (long k = 0; k <= max_power; k++) {
        long n = pow(2, k);
        double result = trapezoidal_integral(a, b, n);
        printf("구간 %ld 적분 결과: %.6lf\n", n, result);
    }

    return 0;
}

