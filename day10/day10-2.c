#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100

typedef enum {
    VIP = 1,
    GOLD,
    SILVER,
    BRONZE
} Rank;

typedef struct Customer {
    char* customerName;
    Rank rank;
    int order_amount;
    int point;
    struct Customer* prev;
    struct Customer* next;
} Customer;

Customer* head = NULL;
Customer* tail = NULL;

void addCustomer();
void deleteCustomer();
void modifyCustomer();
void displayCustomers();
void freeCustomers();
int compareCustomers(Customer* a, Customer* b);

int main() {
    int choice;

    while (1) {
        printf("\n--- 고객 관리 프로그램 ---\n");
        printf("1. 고객 추가\n");
        printf("2. 고객 삭제\n");
        printf("3. 고객 수정\n");
        printf("4. 전체 리스트 출력\n");
        printf("5. 종료\n");
        printf("선택: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            addCustomer();
            break;
        case 2:
            deleteCustomer();
            break;
        case 3:
            modifyCustomer();
            break;
        case 4:
            displayCustomers();
            break;
        case 5:
            freeCustomers();
            exit(0);
        default:
            printf("잘못된 선택입니다. 다시 입력해주세요.\n");
        }
    }

    return 0;
}

void addCustomer() {
    Customer* newCustomer = (Customer*)malloc(sizeof(Customer));
    if (newCustomer == NULL) {
        printf("메모리 할당 실패\n");
        return;
    }

    newCustomer->customerName = (char*)malloc(50 * sizeof(char));
    if (newCustomer->customerName == NULL) {
        printf("메모리 할당 실패\n");
        free(newCustomer);
        return;
    }

    printf("고객 이름: ");
    scanf_s("%49s", newCustomer->customerName, 50);
    printf("고객 등급 (1: VIP, 2: GOLD, 3: SILVER, 4: BRONZE): ");
    int rank;
    scanf_s("%d", &rank);
    newCustomer->rank = (Rank)rank;
    printf("전체 주문량: ");
    scanf_s("%d", &newCustomer->order_amount);
    printf("포인트: ");
    scanf_s("%d", &newCustomer->point);

    newCustomer->prev = tail;
    newCustomer->next = NULL;

    if (tail != NULL) {
        tail->next = newCustomer;
    }
    tail = newCustomer;
    if (head == NULL) {
        head = newCustomer;
    }
    printf("고객이 추가되었습니다.\n");
}

void deleteCustomer() {
    if (head == NULL) {
        printf("삭제할 고객이 없습니다.\n");
        return;
    }

    char name[50];
    printf("삭제할 고객 이름: ");
    scanf_s("%49s", name, 50);

    Customer* current = head;
    while (current != NULL) {
        if (strcmp(current->customerName, name) == 0) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            }
            else {
                head = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            else {
                tail = current->prev;
            }

            free(current->customerName);
            free(current);
            printf("고객이 삭제되었습니다.\n");
            return;
        }
        current = current->next;
    }
    printf("해당 이름을 가진 고객을 찾을 수 없습니다.\n");
}

void modifyCustomer() {
    if (head == NULL) {
        printf("수정할 고객이 없습니다.\n");
        return;
    }

    char name[50];
    printf("수정할 고객 이름: ");
    scanf_s("%49s", name, 50);

    Customer* current = head;
    while (current != NULL) {
        if (strcmp(current->customerName, name) == 0) {
            printf("수정할 고객 이름: ");
            scanf_s("%49s", current->customerName, 50);
            printf("수정할 고객 등급 (1: VIP, 2: GOLD, 3: SILVER, 4: BRONZE): ");
            int rank;
            scanf_s("%d", &rank);
            current->rank = (Rank)rank;
            printf("수정할 전체 주문량: ");
            scanf_s("%d", &current->order_amount);
            printf("수정할 포인트: ");
            scanf_s("%d", &current->point);
            printf("고객 정보가 수정되었습니다.\n");
            return;
        }
        current = current->next;
    }
    printf("해당 이름을 가진 고객을 찾을 수 없습니다.\n");
}

void displayCustomers() {
    if (head == NULL) {
        printf("출력할 고객이 없습니다.\n");
        return;
    }

    Customer* sortedList[MAX_CUSTOMERS];
    int count = 0;
    Customer* current = head;

    // 리스트 복사
    while (current != NULL && count < MAX_CUSTOMERS) {
        sortedList[count++] = current;
        current = current->next;
    }

    // 정렬
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (compareCustomers(sortedList[i], sortedList[j]) > 0) {
                Customer* temp = sortedList[i];
                sortedList[i] = sortedList[j];
                sortedList[j] = temp;
            }
        }
    }

    printf("\n--- 고객 리스트 ---\n");
    for (int i = 0; i < count; i++) {
        printf("이름: %s, 등급: %d, 주문량: %d, 포인트: %d\n",
            sortedList[i]->customerName, sortedList[i]->rank,
            sortedList[i]->order_amount, sortedList[i]->point);
    }
}

int compareCustomers(Customer* a, Customer* b) {
    // 등급이 낮을수록 우선 순위가 높음
    if (a->rank != b->rank)
        return a->rank - b->rank;

    // 전체 주문량이 많을수록 우선 순위가 높음
    if (a->order_amount != b->order_amount)
        return b->order_amount - a->order_amount;

    // 포인트가 많을수록 우선 순위가 높음
    return b->point - a->point;
}

void freeCustomers() {
    Customer* current = head;
    while (current != NULL) {
        Customer* temp = current;
        current = current->next;
        free(temp->customerName);
        free(temp);
    }
}