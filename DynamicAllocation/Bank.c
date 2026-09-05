#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct costumer
{
    char name[20];
    int acno;
    char actype[10];
    float balance;
};

int size = 0;
struct costumer *c = NULL;

/* Create a new account */
int add(char name[],int acno,char actype[])
{
    struct costumer *temp;

    temp = realloc(c, (size + 1) * sizeof(struct costumer));

    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        return -1;
    }

    c = temp;

    strcpy(c[size].name, name);
    strcpy(c[size].actype, actype);
    c[size].acno = acno;
    c[size].balance = 0.0;

    size++;

    printf("Account added successfully\n");

    return 0;
}

/* Sort accounts according to account number */
int sort()
{
    struct costumer temp;

    if (size == 0)
    {
        printf("No accounts available\n");
        return -1;
    }

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (c[j].acno > c[j + 1].acno)
            {
                temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
        }
    }

    printf("After Sorting:\n");

    for (int i = 0; i < size; i++)
    {
        printf("A/c No %d: %d\n", i + 1, c[i].acno);
    }

    return 0;
}

/* Search account using surname */
int searchSurname(char surname[])
{
    char *result;
    int found = 0;

    for (int i = 0; i < size; i++)
    {
        result = strstr(c[i].name, surname);

        if (result != NULL)
        {
            printf("\nA/c No   : %d\n", c[i].acno);
            printf("Name     : %s\n", c[i].name);
            printf("A/c Type : %s\n", c[i].actype);
            printf("Balance  : %.2f\n", c[i].balance);

            found = 1;
        }
    }

    if (!found)
    {
        printf("No account found with that surname\n");
    }

    return 0;
}

/* Deposit / Withdrawal */
int service(int choice, int amount, int acno)
{
    for (int i = 0; i < size; i++)
    {
        if (c[i].acno == acno)
        {
            if (choice == 1)
            {
                c[i].balance += amount;

                printf("Rs.%d deposited successfully\n", amount);
                printf("New Balance: %.2f\n", c[i].balance);

                return 0;
            }
            else if (choice == 2)
            {
                if (c[i].balance - amount < 500)
                {
                    printf("Withdrawal failed: Minimum balance of Rs.500 must be maintained\n");
                    return 0;
                }
                else
                {
                    c[i].balance -= amount;

                    printf("Rs.%d withdrawn successfully\n", amount);
                    printf("New Balance: %.2f\n", c[i].balance);

                    return 0;
                }
            }
            else
            {
                printf("Invalid service choice\n");
                return -1;
            }
        }
    }

    printf("Invalid Account No\n");
    return -1;
}

int main()
{
    int choice;

    do
    {
        printf("\n");
        printf("1. Create Account\n");
        printf("2. Sort\n");
        printf("3. Search Surname\n");
        printf("4. Services\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                char name[20];
                char actype[10];
                int acno;

                printf("Enter Name, Account Number, Account Type:\n");
                scanf("%19s %d %9s", name,&acno,actype);

                add(name, acno,actype);

                break;
            }

            case 2:
                sort();
                break;

            case 3:
            {
                char search[20];

                printf("Enter the surname to be searched: ");
                scanf("%19s", search);

                searchSurname(search);

                break;
            }

            case 4:
            {
                int acno;
                int amount;
                int ch;

                printf("Enter the A/c No: ");
                scanf("%d", &acno);

                printf("1. Deposit\n");
                printf("2. Withdrawal\n");

                printf("Enter your choice: ");
                scanf("%d", &ch);

                printf("Enter the amount: ");
                scanf("%d", &amount);

                service(ch, amount, acno);

                break;
            }

            case 5:
                printf("Exiting....\n");
                break;

            default:
                printf("Invalid Input\n");
        }

    } while (choice != 5);

    free(c);

    return 0;
}