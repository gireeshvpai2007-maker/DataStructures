

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int id;
    char destination[10];
    struct node *left;
    struct node *right;
};

struct node **stack = NULL;
int top = -1;
int capacity = 0;

struct node *root = NULL;

/* Search for a package ID in the BST */
int searchBST(struct node *root, int key) {
    if (root == NULL)
        return 0;

    if (root->id == key)
        return 1;

    if (key < root->id)
        return searchBST(root->left, key);

    return searchBST(root->right, key);
}

/* Check duplicate ID in the pending stack */
int isDuplicateStack(int id) {
    for (int i = 0; i <= top; i++) {
        if (stack[i]->id == id)
            return 1;
    }
    return 0;
}

/* Push a package onto the stack */
int push(struct node *package) {
    if (top + 1 == capacity) {
        int newCapacity = (capacity == 0) ? 2 : capacity * 2;

        struct node **temp = realloc(
            stack, newCapacity * sizeof(*stack)
        );

        if (temp == NULL)
            return 0;

        stack = temp;
        capacity = newCapacity;
    }

    stack[++top] = package;
    return 1;
}

/* Pop a package from the stack */
struct node *pop(void) {
    if (top == -1)
        return NULL;

    return stack[top--];
}

/* Add a package after validation */
void AddPackage(void) {
    int id;
    char dest[10];

    printf("Enter package ID: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID input.\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        return;
    }

    printf("Enter destination (max 9 characters, no spaces): ");
    if (scanf("%9s", dest) != 1) {
        printf("Invalid destination.\n");
        return;
    }

    if (isDuplicateStack(id) || searchBST(root, id)) {
        printf("Duplicate package ID! Package not added.\n");
        return;
    }

    struct node *package = malloc(sizeof(*package));

    if (package == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    package->id = id;
    strcpy(package->destination, dest);
    package->left = NULL;
    package->right = NULL;

    if (!push(package)) {
        printf("Unable to expand stack.\n");
        free(package);
        return;
    }

    printf("Package added to pending stack.\n");
}

/* Insert a dispatched package into the BST */
struct node *insertBST(struct node *root, struct node *package) {
    if (root == NULL)
        return package;

    if (package->id < root->id)
        root->left = insertBST(root->left, package);
    else if (package->id > root->id)
        root->right = insertBST(root->right, package);

    return root;
}

/* Dispatch the most recently added pending package */
void DispatchPackage(void) {
    struct node *package = pop();

    if (package == NULL) {
        printf("No pending packages to dispatch.\n");
        return;
    }

    package->left = NULL;
    package->right = NULL;

    root = insertBST(root, package);

    printf("Dispatched package ID: %d, Destination: %s\n",
           package->id, package->destination);
}

/* Display pending packages from top to bottom */
void DisplayPendingPackages(void) {
    if (top == -1) {
        printf("No pending packages.\n");
        return;
    }

    printf("\nPending packages (top to bottom):\n");

    for (int i = top; i >= 0; i--) {
        printf("ID: %d, Destination: %s\n",
               stack[i]->id, stack[i]->destination);
    }
}

/* Search for a dispatched package */
void SearchDispatchedPackages(void) {
    int key;

    printf("Enter package ID to search: ");
    if (scanf("%d", &key) != 1) {
        printf("Invalid ID input.\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        return;
    }

    if (searchBST(root, key))
        printf("Package ID %d found in dispatched packages.\n", key);
    else
        printf("Package ID %d not found in dispatched packages.\n", key);
}

/* Display dispatched packages in ascending ID order */
void DisplayDispatchedPackages(struct node *root) {
    if (root == NULL)
        return;

    DisplayDispatchedPackages(root->left);

    printf("ID: %d, Destination: %s\n",
           root->id, root->destination);

    DisplayDispatchedPackages(root->right);
}

void freeBST(struct node *root) {
    if (root == NULL)
        return;

    freeBST(root->left);
    freeBST(root->right);
    free(root);
}

int main(void) {
    int choice;

    do {
        printf("\n--- Package Management System ---\n");
        printf("1. Add Package\n");
        printf("2. Dispatch Package\n");
        printf("3. Display Pending Packages\n");
        printf("4. Search Dispatched Packages\n");
        printf("5. Display Dispatched Packages (Inorder)\n");
        printf("0. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid menu choice.\n");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {}
            continue;
        }

        switch (choice) {
            case 1:
                AddPackage();
                break;

            case 2:
                DispatchPackage();
                break;

            case 3:
                DisplayPendingPackages();
                break;

            case 4:
                SearchDispatchedPackages();
                break;

            case 5:
                if (root == NULL)
                    printf("No dispatched packages.\n");
                else
                    DisplayDispatchedPackages(root);
                break;

            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    /* Free pending packages */
    for (int i = 0; i <= top; i++)
        free(stack[i]);

    free(stack);
    freeBST(root);

    return 0;
}
