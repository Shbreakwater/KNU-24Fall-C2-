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

    printf("�л� �� �Է�: ");
    scanf_s("%d", &N);

    students = (Student*)malloc(N * sizeof(Student));

    for (int i = 0; i < N; i++) {
        printf("�л� %d�� �й� �Է�: ", i + 1);
        scanf_s("%d", &students[i].snum);

        printf("�л� %d�� �̸� �Է�: ", i + 1);
        scanf_s("%s", students[i].name, (unsigned)_countof(students[i].name));

        printf("�л� %d�� ���� �Է�: ", i + 1);
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

    printf("\n�л� ����:\n");
    for (int i = 0; i < N; i++) {
        printf("�й�: %d, �̸�: %s, ����: %d\n", students[i].snum, students[i].name, students[i].score);
    }

    printf("\n�ְ� ����: %d\n", max);
    printf("���� ����: %d\n", min);
    printf("��� ����: %.2f\n", avg);

    free(students);

    return 0;
}
