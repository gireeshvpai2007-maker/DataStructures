
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[30];
    int reg, marks;
    struct node *prev, *next;
    struct node *left, *right;
};

struct node **stack = NULL;
int top = -1;

struct node *head = NULL, *tail = NULL;
struct node *root = NULL;

/* Search registration number in DLL */
int searchDLL(int reg)
{
    struct node *temp = head;

    while (temp != NULL)
    {
        if (temp->reg == reg)
            return 1;

        temp = temp->next;
    }

    return 0;
}

/* Search registration number in BST */
int searchBST(struct node *r, int reg)
{
    if (r == NULL)
        return 0;

    if (r->reg == reg)
        return 1;

    if (reg < r->reg)
        return searchBST(r->left, reg);

    return searchBST(r->right, reg);
}

/* Push student pointer onto stack */
int push(struct node *a)
{
    if (searchDLL(a->reg) || searchBST(root, a->reg))
    {
        printf("Duplicate registration number! Not added.\n");
        return 0;
    }

    struct node **temp = realloc(
        stack, (top + 2) * sizeof(struct node *)
    );

    if (temp == NULL)
    {
        printf("Stack memory allocation failed!\n");
        return 0;
    }

    stack = temp;
    stack[++top] = a;

    return 1;
}

/* Pop student pointer from stack */
struct node *pop(void)
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
        return NULL;
    }

    return stack[top--];
}

/* Read student details */
struct node *StudentDetails(void)
{
    struct node *a = malloc(sizeof(struct node));

    if (a == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    printf("Enter student name: ");
    if (scanf("%29s", a->name) != 1)
    {
        free(a);
        return NULL;
    }

    printf("Enter registration number: ");
    if (scanf("%d", &a->reg) != 1)
    {
        free(a);
        return NULL;
    }

    printf("Enter marks: ");
    if (scanf("%d", &a->marks) != 1)
    {
        free(a);
        return NULL;
    }

    if (a->marks < 0 || a->marks > 100)
    {
        printf("Marks must be between 0 and 100!\n");
        free(a);
        return NULL;
    }

    a->prev = a->next = NULL;
    a->left = a->right = NULL;

    return a;
}

/* Insert student into DLL */
void insertDLL(struct node *a)
{
    a->next = NULL;
    a->prev = tail;

    if (head == NULL)
        head = tail = a;
    else
    {
        tail->next = a;
        tail = a;
    }
}

/* Insert student into BST */
struct node *insertBST(struct node *r, struct node *a)
{
    if (r == NULL)
        return a;

    if (a->reg < r->reg)
        r->left = insertBST(r->left, a);
    else if (a->reg > r->reg)
        r->right = insertBST(r->right, a);

    return r;
}

/* Add student after duplicate check and successful push */
void addStudent(void)
{
    struct node *a = StudentDetails();

    if (a == NULL)
        return;

    if (!push(a))
    {
        free(a);
        return;
    }

    insertDLL(a);

    printf("Student added to stack and DLL successfully!\n");
}

/* Pop from stack and insert into BST */
void dispatchStudent(void)
{
    struct node *a = pop();

    if (a == NULL)
        return;

    if (searchBST(root, a->reg))
    {
        printf("Student already exists in BST!\n");
        return;
    }

    root = insertBST(root, a);

    printf("Student inserted into BST successfully!\n");
}

/* Display DLL */
void displayDLL(void)
{
    struct node *temp = head;

    if (temp == NULL)
    {
        printf("DLL is empty!\n");
        return;
    }

    printf("\nStudent records in DLL:\n");

    while (temp != NULL)
    {
        printf("Name: %s | Reg: %d | Marks: %d\n",
               temp->name, temp->reg, temp->marks);

        temp = temp->next;
    }
}

/* Display BST in preorder */
void preorder(struct node *r)
{
    if (r == NULL)
        return;

    printf("%d ", r->reg);
    preorder(r->left);
    preorder(r->right);
}

/* Display students in ascending registration number */
void displayAscending(struct node *r)
{
    if (r == NULL)
        return;

    displayAscending(r->left);

    printf("Name: %s | Reg: %d | Marks: %d\n",
           r->name, r->reg, r->marks);

    displayAscending(r->right);
}

/* Display students who scored strictly greater than 40 */
void displayPassed(struct node *r)
{
    if (r == NULL)
        return;

    displayPassed(r->left);

    if (r->marks > 40)
        printf("%s | Reg: %d | Marks: %d\n",
               r->name, r->reg, r->marks);

    displayPassed(r->right);
}

/* Count leaf nodes in BST */
int countLeaves(struct node *r)
{
    if (r == NULL)
        return 0;

    if (r->left == NULL && r->right == NULL)
        return 1;

    return countLeaves(r->left) + countLeaves(r->right);
}

int main(void)
{
    int choice;

    do
    {
        printf("\n===== STUDENT RECORD SYSTEM =====\n");
        printf("1. Enter student details\n");
        printf("2. Pop stack and insert into BST\n");
        printf("3. Display DLL\n");
        printf("4. Display BST preorder\n");
        printf("5. Display all students in ascending reg no\n");
        printf("6. Display students who passed (> 40)\n");
        printf("7. Count BST leaf nodes\n");
        printf("0. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
            break;

        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                dispatchStudent();
                break;

            case 3:
                displayDLL();
                break;

            case 4:
                if (root == NULL)
                    printf("BST is empty!\n");
                else
                {
                    preorder(root);
                    printf("\n");
                }
                break;

            case 5:
                if (root == NULL)
                    printf("BST is empty!\n");
                else
                    displayAscending(root);
                break;

            case 6:
                if (root == NULL)
                    printf("BST is empty!\n");
                else
                    displayPassed(root);
                break;

            case 7:
                printf("Number of leaf nodes: %d\n",
                       countLeaves(root));
                break;

            case 0:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);

    /* Free each shared student node exactly once */
    struct node *temp = head;

    while (temp != NULL)
    {
        struct node *next = temp->next;
        free(temp);
        temp = next;
    }

    free(stack);

    return 0;
}
