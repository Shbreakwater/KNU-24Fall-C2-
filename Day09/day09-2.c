#include <stdio.h>
#include <string.h>

struct Product {
    int id;
    char name[30];
    int price;
};

void printProduct(struct Product p) {
    printf("��ǰ ID: %d\n", p.id);
    printf("��ǰ��: %s\n", p.name);
    printf("����: %d��\n", p.price);
}

int main() {
    struct Product products[5];
    int count = 0;
    int id;

    while (count < 5) {
        printf("��ǰ ������ �Է��ϼ��� (�Է� �ߴ��� id�� 0 �Է�)\n");

        printf("��ǰ ID: ");
        scanf_s("%d", &id);


        if (id == 0) {
            break;
        }

        products[count].id = id;

        printf("��ǰ��: ");
        getchar();
        fgets(products[count].name, sizeof(products[count].name), stdin);

        products[count].name[strcspn(products[count].name, "\n")] = 0;

        printf("����: ");
        scanf_s("%d", &products[count].price);

        count++;
    }
    printf("\n<<�Էµ� ��ǰ ���>>\n");
    for (int i = 0; i < count; i++) {
        printProduct(products[i]);
        printf("\n");
    }

    return 0;
}