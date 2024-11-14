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
        printf("\n--- �� ���� ���α׷� ---\n");
        printf("1. �� �߰�\n");
        printf("2. �� ����\n");
        printf("3. �� ����\n");
        printf("4. ��ü ����Ʈ ���\n");
        printf("5. ����\n");
        printf("����: ");
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
            printf("�߸��� �����Դϴ�. �ٽ� �Է����ּ���.\n");
        }
    }

    return 0;
}

void addCustomer() {
    Customer* newCustomer = (Customer*)malloc(sizeof(Customer));
    if (newCustomer == NULL) {
        printf("�޸� �Ҵ� ����\n");
        return;
    }

    newCustomer->customerName = (char*)malloc(50 * sizeof(char));
    if (newCustomer->customerName == NULL) {
        printf("�޸� �Ҵ� ����\n");
        free(newCustomer);
        return;
    }

    printf("�� �̸�: ");
    scanf_s("%49s", newCustomer->customerName, 50);
    printf("�� ��� (1: VIP, 2: GOLD, 3: SILVER, 4: BRONZE): ");
    int rank;
    scanf_s("%d", &rank);
    newCustomer->rank = (Rank)rank;
    printf("��ü �ֹ���: ");
    scanf_s("%d", &newCustomer->order_amount);
    printf("����Ʈ: ");
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
    printf("���� �߰��Ǿ����ϴ�.\n");
}

void deleteCustomer() {
    if (head == NULL) {
        printf("������ ���� �����ϴ�.\n");
        return;
    }

    char name[50];
    printf("������ �� �̸�: ");
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
            printf("���� �����Ǿ����ϴ�.\n");
            return;
        }
        current = current->next;
    }
    printf("�ش� �̸��� ���� ���� ã�� �� �����ϴ�.\n");
}

void modifyCustomer() {
    if (head == NULL) {
        printf("������ ���� �����ϴ�.\n");
        return;
    }

    char name[50];
    printf("������ �� �̸�: ");
    scanf_s("%49s", name, 50);

    Customer* current = head;
    while (current != NULL) {
        if (strcmp(current->customerName, name) == 0) {
            printf("������ �� �̸�: ");
            scanf_s("%49s", current->customerName, 50);
            printf("������ �� ��� (1: VIP, 2: GOLD, 3: SILVER, 4: BRONZE): ");
            int rank;
            scanf_s("%d", &rank);
            current->rank = (Rank)rank;
            printf("������ ��ü �ֹ���: ");
            scanf_s("%d", &current->order_amount);
            printf("������ ����Ʈ: ");
            scanf_s("%d", &current->point);
            printf("�� ������ �����Ǿ����ϴ�.\n");
            return;
        }
        current = current->next;
    }
    printf("�ش� �̸��� ���� ���� ã�� �� �����ϴ�.\n");
}

void displayCustomers() {
    if (head == NULL) {
        printf("����� ���� �����ϴ�.\n");
        return;
    }

    Customer* sortedList[MAX_CUSTOMERS];
    int count = 0;
    Customer* current = head;

    // ����Ʈ ����
    while (current != NULL && count < MAX_CUSTOMERS) {
        sortedList[count++] = current;
        current = current->next;
    }

    // ����
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (compareCustomers(sortedList[i], sortedList[j]) > 0) {
                Customer* temp = sortedList[i];
                sortedList[i] = sortedList[j];
                sortedList[j] = temp;
            }
        }
    }

    printf("\n--- �� ����Ʈ ---\n");
    for (int i = 0; i < count; i++) {
        printf("�̸�: %s, ���: %d, �ֹ���: %d, ����Ʈ: %d\n",
            sortedList[i]->customerName, sortedList[i]->rank,
            sortedList[i]->order_amount, sortedList[i]->point);
    }
}

int compareCustomers(Customer* a, Customer* b) {
    // ����� �������� �켱 ������ ����
    if (a->rank != b->rank)
        return a->rank - b->rank;

    // ��ü �ֹ����� �������� �켱 ������ ����
    if (a->order_amount != b->order_amount)
        return b->order_amount - a->order_amount;

    // ����Ʈ�� �������� �켱 ������ ����
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