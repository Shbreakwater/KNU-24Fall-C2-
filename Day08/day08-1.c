#include <stdio.h>
#include <ctype.h>
#include <string.h>

void reverseString(char* str) {
    char* start = str;
    char* end = str + strlen(str) - 1;

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main() {
    char input[100], processed[100];
    int j = 0;

    printf("문자열을 입력하세요: ");
    fgets(input, sizeof(input), stdin);

    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            processed[j++] = input[i];
        }
    }
    processed[j] = '\0';

    reverseString(processed);

    printf("뒤집어진 문자열: %s\n", processed);

    return 0;
}
