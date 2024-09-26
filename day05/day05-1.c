#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    int* snum;
    char** name;
    int* score;
    int max, min;
    float sum = 0, avg;

    
    printf("학생 수 입력: ");
    scanf_s("%d", &N);

    snum = (int*)malloc(N * sizeof(int));
    score = (int*)malloc(N * sizeof(int));
    name = (char**)malloc(N * sizeof(char*));
    for (int i = 0; i < N; i++) {
        name[i] = (char*)malloc(100 * sizeof(char));
    }

    for (int i = 0; i < N; i++) {
        printf("학번: ");
        scanf_s("%d", &snum[i]);

        printf("이름: ");
        scanf_s("%s", name[i], 100);

        printf("점수: ");
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

    printf("\n학생 정보:\n");
    for (int i = 0; i < N; i++) {
        printf("%d %s %d\n", snum[i], name[i], score[i]);
    }

    printf("\n최고 점수: %d\n", max);
    printf("최저 점수: %d\n", min);
    printf("평균 점수: %.2f\n", avg);

    free(snum);
    for (int i = 0; i < N; i++) {
        free(name[i]);
    }
    free(name);
    free(score);

    return 0;
}