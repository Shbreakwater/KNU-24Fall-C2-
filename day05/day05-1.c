#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    int* snum;
    char** name;
    int* score;
    int max, min;
    float sum = 0, avg;

    
    printf("�л� �� �Է�: ");
    scanf_s("%d", &N);

    snum = (int*)malloc(N * sizeof(int));
    score = (int*)malloc(N * sizeof(int));
    name = (char**)malloc(N * sizeof(char*));
    for (int i = 0; i < N; i++) {
        name[i] = (char*)malloc(100 * sizeof(char));
    }

    for (int i = 0; i < N; i++) {
        printf("�й�: ");
        scanf_s("%d", &snum[i]);

        printf("�̸�: ");
        scanf_s("%s", name[i], 100);

        printf("����: ");
        scanf_s("%d", &score[i]);

        
        sum += score[i];

        
        if (i == 0) {
            max = min = score[i];
        }
        else {
            if (score[i] > max) max = score[i];
            if (score[i] < min) min = score[i];
        }
    }

    avg = sum / N;

    printf("\n�л� ����:\n");
    for (int i = 0; i < N; i++) {
        printf("%d %s %d\n", snum[i], name[i], score[i]);
    }

    printf("\n�ְ� ����: %d\n", max);
    printf("���� ����: %d\n", min);
    printf("��� ����: %.2f\n", avg);

    free(snum);
    for (int i = 0; i < N; i++) {
        free(name[i]);
    }
    free(name);
    free(score);

    return 0;
}