#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coef, exp;
    struct node *next;
};

struct node *createnode(int coef, int exp)
{
    struct node *new_Node =
        (struct node *)malloc(sizeof(struct node));

    new_Node->coef = coef;
    new_Node->exp = exp;
    new_Node->next = NULL;

    return new_Node;
}

int insert(struct node **head, int coef, int exp)
{
    struct node *a = createnode(coef, exp);

    if (*head == NULL)
    {
        *head = a;
        return 0;
    }

    struct node *temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = a;

    return 0;
}

struct node *polyadd(struct node **ha, struct node **hb)
{
    struct node *tempA = *ha;
    struct node *tempB = *hb;
    struct node *hc = NULL;

    while (tempA != NULL && tempB != NULL)
    {
        if (tempA->exp == tempB->exp)
        {
            int sum = tempA->coef + tempB->coef;

            if (sum != 0)
                insert(&hc, sum, tempA->exp);

            tempA = tempA->next;
            tempB = tempB->next;
        }
        else if (tempA->exp > tempB->exp)
        {
            insert(&hc, tempA->coef, tempA->exp);
            tempA = tempA->next;
        }
        else
        {
            insert(&hc, tempB->coef, tempB->exp);
            tempB = tempB->next;
        }
    }

    while (tempA != NULL)
    {
        insert(&hc, tempA->coef, tempA->exp);
        tempA = tempA->next;
    }

    while (tempB != NULL)
    {
        insert(&hc, tempB->coef, tempB->exp);
        tempB = tempB->next;
    }

    return hc;
}

int main()
{
    struct node *ha = NULL, *hb = NULL;

    printf("Creation of polynomial A\n");
    printf("Enter the no of terms in polynomial A\n");

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int coef, exp;

        printf("Enter coefficient and exponent\n");
        scanf("%d%d", &coef, &exp);

        insert(&ha, coef, exp);
    }

    printf("Creation of polynomial B\n");
    printf("Enter the no of terms in polynomial B\n");

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int coef, exp;

        printf("Enter coefficient and exponent\n");
        scanf("%d%d", &coef, &exp);

        insert(&hb, coef, exp);
    }

    printf("Added Polynomial P = ");

    struct node *c = polyadd(&ha, &hb);
    struct node *temp = c;

    while (temp != NULL)
    {
        if (temp->exp == 0)
        {
            printf("%d", temp->coef);
        }
        else if (temp->coef > 0)
        {
            printf("%dx^%d", temp->coef, temp->exp);
        }
        else
        {
            printf("(%d)x^%d", temp->coef, temp->exp);
        }

        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }

    return 0;
}