#include <stdio.h>

int main() {
    int n;
    int id;
    char name[50];
    float score, max, min, sum = 0;

    printf("�л� �� �Է�: ");
    scanf_s("%d", &n);

    printf("�л� 1�� �й� �Է�: ");
    scanf_s("%d", &id);

    printf("�л� 1�� �̸� �Է�: ");
    scanf_s("%s", name);

    printf("�л� 1�� ���� �Է�: ");
    scanf_s("%f", &score);
    max = min = score;
    sum = score;
    for (int i = 2; i <= n; i++) {
        printf("\n�л� %d�� �й� �Է�: ", i);
        scanf_s("%d", &id);

        printf("�л� %d�� �̸� �Է�: ", i);
        scanf_s("%s", name);

        printf("�л� %d�� ���� �Է�: ", i);
        scanf_s("%f", &score);

        if (score > max) max = score;
        if (score < min) min = score;
        sum += score;
    }
    float average = sum / n;
    printf("\n�ְ� ����: %.2f\n", max);
    printf("���� ����: %.2f\n", min);
    printf("��� ����: %.2f\n", average);

    return 0;
}