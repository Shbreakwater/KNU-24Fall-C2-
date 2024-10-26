#include <stdio.h>

struct Vector3D {
    int x, y, z;
};

struct Vector3D add(struct Vector3D v1, struct Vector3D v2) {
    struct Vector3D result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    result.z = v1.z + v2.z;
    return result;
}

struct Vector3D subtract(struct Vector3D v1, struct Vector3D v2) {
    struct Vector3D result;
    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
    result.z = v1.z - v2.z;
    return result;
}

int dotProduct(struct Vector3D v1, struct Vector3D v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

struct Vector3D crossProduct(struct Vector3D v1, struct Vector3D v2) {
    struct Vector3D result;
    result.x = v1.y * v2.z - v1.z * v2.y;
    result.y = v1.z * v2.x - v1.x * v2.z;
    result.z = v1.x * v2.y - v1.y * v2.x;
    return result;
}

void displayVector(struct Vector3D v) {
    printf("x: %d\t y: %d\t z: %d\n", v.x, v.y, v.z);
}

int main() {
    struct Vector3D vec1;
    struct Vector3D vec2;

    printf("첫번째 벡터 (x, y, z) : ");
    scanf_s("%d %d %d", &vec1.x, &vec1.y, &vec1.z);

    /*(void)getchar(); */
    printf("두번째 벡터 (x, y, z) : ");
    scanf_s("%d %d %d", &vec2.x, &vec2.y, &vec2.z);

    printf("입력된 첫번째 벡터\t %d,\t%d,\t%d\n", vec1.x, vec1.y, vec1.z);
    printf("입력된 두번째 벡터\t %d,\t%d,\t%d\n", vec2.x, vec2.y, vec2.z);

    int command = 0;
    do {
        printf("\n---------------------------\n");
        printf("1. 벡터의 합\n");
        printf("2. 벡터의 차\n");
        printf("3. 벡터의 외적\n");
        printf("4. 벡터의 내적\n");
        printf("5. 종료\n");
        printf("---------------------------\n");
        printf("명령 입력: ");

        if (scanf_s("%d", &command) != 1) {
            printf("잘못된 입력입니다. 숫자를 입력하세요.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (command) {
        case 1: {
            struct Vector3D sum = add(vec1, vec2);
            printf("---------------------------\n");
            printf("벡터의 합: ");
            displayVector(sum);
            break;
        }
        case 2: {
            struct Vector3D diff = subtract(vec1, vec2);
            printf("---------------------------\n");
            printf("벡터의 차: ");
            displayVector(diff);
            break;
        }
        case 3: {
            struct Vector3D cross = crossProduct(vec1, vec2);
            printf("---------------------------\n");
            printf("벡터의 외적은 \tx:%d\t y:%d\t z:%d\n", cross.x, cross.y, cross.z);
            break;
        }
        case 4: {
            int dot = dotProduct(vec1, vec2);
            printf("---------------------------\n");
            printf("벡터의 내적은 \tvec1 · vec2 = %d\n", dot);
            break;
        }
        case 5:
            printf("프로그램 종료\n");
            break;
        default:
            printf("잘못된 명령입니다. 1~5 사이의 숫자를 입력하세요.\n");
        }
    } while (command != 5);

    return 0;
}
