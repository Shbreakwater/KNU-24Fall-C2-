#include <stdio.h>

int solution(int N) {
    int battery_usage = 0;

    while (N > 0) {
        if (N % 2 == 1) {
            battery_usage++;
            N--;
        }
        N /= 2;
    }

    return battery_usage;
}

int main() {
    printf("%d\n", solution(5));
    printf("%d\n", solution(6));
    printf("%d\n", solution(5000));
    return 0;
}
