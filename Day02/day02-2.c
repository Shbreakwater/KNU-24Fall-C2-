#include <stdio.h>

int main() {
    int i;
    for (i = 0; i <= 99; i++) {
       
        if (i % 3 == 0 && i % 4 == 0) {
            
            if (i % 7 == 0) {
                printf("%d (3�� 4�� ������̸鼭 7�� ���)\n", i);
            }
            else {
                printf("%d (3�� 4�� �����)\n", i);
            }
        }
       
        else if (i % 7 == 0) {
            printf("%d (7�� ���)\n", i);
        }
    }
    return 0;
}