/*Employee Management System
Write a menu-driven C program to create a structure named Employee and maintain an array of these structures.
Attributes Required:
Name (String)
Employee ID (Integer)
Department (String)
Monthly Salary (Float)
Operations Required:
Sort the list of employees by their Employee ID using recursive selection sort.
Find and display the details of the employee with the highest monthly*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Employee
{
    char name[20];
    int id;
    char dep[15];
    float salary;
};

struct Employee *e = NULL;
int size = 0;


/* Add employee */
void add(int id, char name[], char dep[], float salary)
{
    e = (struct Employee *)realloc(e,
                                   (size + 1) * sizeof(struct Employee));

    e[size].id = id;
    strcpy(e[size].name, name);
    strcpy(e[size].dep, dep);
    e[size].salary = salary;

    size++;

    printf("Employee added successfully\n");
}


/* Recursive Selection Sort */
void sort(int i, int j, int min)
{
    struct Employee temp;

    /* All positions are sorted */
    if(i >= size - 1)
    {
        return;
    }

    /* Search for minimum ID */
    if(j < size)
    {
        if(e[j].id < e[min].id)
        {
            min = j;
        }

        sort(i, j + 1, min);
    }
    else
    {
        /* Put minimum element at position i */
        if(min != i)
        {
            temp = e[i];
            e[i] = e[min];
            e[min] = temp;
        }

        /* Sort next position */
        sort(i + 1, i + 2, i + 1);
    }
}


/* Display employees */
void display()
{
    if(size == 0)
    {
        printf("No employees available\n");
        return;
    }

    printf("\nEmployee Details:\n");

    for(int i = 0; i < size; i++)
    {
        printf("ID:%d Name:%s Department:%s Salary:%.2f\n",
               e[i].id,
               e[i].name,
               e[i].dep,
               e[i].salary);
    }
}


/* Find employee with highest salary */
void highest()
{
    if(size == 0)
    {
        printf("No employees available\n");
        return;
    }

    int high = 0;

    for(int i = 1; i < size; i++)
    {
        if(e[i].salary > e[high].salary)
        {
            high = i;
        }
    }

    printf("\nHighest Salary Details\n");
    printf("ID:%d Name:%s Department:%s Salary:%.2f\n",
           e[high].id,
           e[high].name,
           e[high].dep,
           e[high].salary);
}


int main()
{
    int choice;

    do
    {
        printf("\n1.Insert 2.Sort 3.Highest Salary Details 4.Display 5.Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                int id;
                char name[20];
                char dep[15];
                float salary;

                printf("Enter id,name,department,salary\n");
                scanf("%d%s%s%f",
                      &id,
                      name,
                      dep,
                      &salary);

                add(id, name, dep, salary);

                break;
            }

            case 2:
            {
                if(size == 0)
                {
                    printf("No employees available\n");
                    break;
                }

                sort(0, 1, 0);

                printf("Sorted Successfully\n");

                for(int i = 0; i < size; i++)
                {
                    printf("%d ", e[i].id);
                }

                printf("\n");

                break;
            }

            case 3:
                highest();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Input\n");
        }

    } while(choice != 5);

    free(e);

    return 0;
}

