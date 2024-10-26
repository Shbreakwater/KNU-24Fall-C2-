#include <stdio.h>
#include <string.h>

struct Product {
    int id;
    char name[30];
    int price;
};

void printProduct(struct Product p) {
    printf("상품 ID: %d\n", p.id);
    printf("상품명: %s\n", p.name);
    printf("가격: %d원\n", p.price);
}

int main() {
    struct Product products[5];
    int count = 0;
    int id;

    while (count < 5) {
        printf("상품 정보를 입력하세요 (입력 중단은 id에 0 입력)\n");

        printf("상품 ID: ");
        scanf_s("%d", &id);


        if (id == 0) {
            break;
        }

        products[count].id = id;

        printf("상품명: ");
        getchar();
        fgets(products[count].name, sizeof(products[count].name), stdin);

        products[count].name[strcspn(products[count].name, "\n")] = 0;

        printf("가격: ");
        scanf_s("%d", &products[count].price);

        count++;
    }
    printf("\n<<입력된 상품 목록>>\n");
    for (int i = 0; i < count; i++) {
        printProduct(products[i]);
        printf("\n");
    }

    return 0;
}