#include <stdio.h>

int main() {
    int n;
    int id;
    char name[50];
    float score, max, min, sum = 0;

    printf("학생 수 입력: ");
    scanf_s("%d", &n);

    printf("학생 1의 학번 입력: ");
    scanf_s("%d", &id);

    printf("학생 1의 이름 입력: ");
    scanf_s("%s", name);

    printf("학생 1의 점수 입력: ");
    scanf_s("%f", &score);
    max = min = score;
    sum = score;
    for (int i = 2; i <= n; i++) {
        printf("\n학생 %d의 학번 입력: ", i);
        scanf_s("%d", &id);

        printf("학생 %d의 이름 입력: ", i);
        scanf_s("%s", name);

        printf("학생 %d의 점수 입력: ", i);
        scanf_s("%f", &score);

        if (score > max) max = score;
        if (score < min) min = score;
        sum += score;
    }
    float average = sum / n;
    printf("\n최고 점수: %.2f\n", max);
    printf("최저 점수: %.2f\n", min);
    printf("평균 점수: %.2f\n", average);

    return 0;
}