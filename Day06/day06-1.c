#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fifth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1; head->next = second;
    second->data = 2; second->next = third;
    third->data = 3; third->next = fourth;
    fourth->data = 4; fourth->next = fifth;
    fifth->data = 5; fifth->next = NULL;

    printf("���� ����Ʈ: ");
    printList(head);

    second->next = fourth;
    free(third);

    printf("3��° ��带 ������ �� ���� ����Ʈ: ");
    printList(head);

    return 0;
}