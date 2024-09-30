#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int snum;
    char name[100];
    int score;
} Student;

int main() {
    int N;
    Student* students;
    int max, min;
    float sum = 0, avg;

    printf("학생 수 입력: ");
    scanf_s("%d", &N);

    students = (Student*)malloc(N * sizeof(Student));

    for (int i = 0; i < N; i++) {
        printf("학생 %d의 학번 입력: ", i + 1);
        scanf_s("%d", &students[i].snum);

        printf("학생 %d의 이름 입력: ", i + 1);
        scanf_s("%s", students[i].name, (unsigned)_countof(students[i].name));

        printf("학생 %d의 점수 입력: ", i + 1);
        scanf_s("%d", &students[i].score);

        sum += students[i].score;

    
        if (i == 0) {
            max = min = students[i].score;
        }
        else {
            if (students[i].score > max) max = students[i].score;
            if (students[i].score < min) min = students[i].score;
        }
    }

    avg = sum / N;

    printf("\n학생 정보:\n");
    for (int i = 0; i < N; i++) {
        printf("학번: %d, 이름: %s, 점수: %d\n", students[i].snum, students[i].name, students[i].score);
    }

    printf("\n최고 점수: %d\n", max);
    printf("최저 점수: %d\n", min);
    printf("평균 점수: %.2f\n", avg);

    free(students);

    return 0;
}
