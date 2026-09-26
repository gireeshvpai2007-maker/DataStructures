#include <stdio.h>
#include <stdlib.h>

struct Node {
    int power;
    struct Node *next;
};

struct Node* insert(struct Node *head, int power) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->power = power;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

int main() {
    struct Node *head = NULL;
    struct Node *temp;
    int degree, power;

    printf("Enter highest degree: ");
    scanf("%d", &degree);

    printf("Enter powers having coefficient 1:\n");

    while (1) {
        scanf("%d", &power);

        if (power == -1)
            break;

        head = insert(head, power);
    }

    printf("Pattern: ");

    for (int i = degree; i >= 0; i--) {
        temp = head;
        int found = 0;

        while (temp != NULL) {
            if (temp->power == i) {
                found = 1;
                break;
            }
            temp = temp->next;
        }

        printf("%d", found);
    }

    return 0;
}