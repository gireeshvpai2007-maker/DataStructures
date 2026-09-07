
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct Book
{
    int id;
    char author[20];
    char title[20];
    float price;
};

struct Book *b;
int size=0;

/* Sort books according to Title */
void sort()
{
    struct Book temp;

    for(int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(strcmp(b[i].title,b[j].title)>0)
            {
                temp=b[i];
                b[i]=b[j];
                b[j]=temp;
            }
        }
    }
}

/* Recursive Binary Search */
int search(int low,int high,char title[])
{
    if(low>high)
    {
        return -1;
    }

    int mid=low+(high-low)/2;

    if(strcmp(title,b[mid].title)==0)
    {
        return mid;
    }
    else if(strcmp(title,b[mid].title)<0)
    {
        return search(low,mid-1,title);
    }
    else
    {
        return search(mid+1,high,title);
    }
}

int display(int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Id:%d  Title:%s  Author:%s  Price:%f\n",
               b[i].id,b[i].title,b[i].author,b[i].price);
    }

    return 0;
}

int insert(int id,char author[],char title[],float price)
{
    b=(struct Book *)realloc(b,(size+1)*sizeof(struct Book));

    b[size].id=id;
    strcpy(b[size].author,author);
    strcpy(b[size].title,title);
    b[size].price=price;

    size++;

    printf("Book Inserted Successfully\n");

    return 0;
}

int main()
{
    int choice;

    do
    {
        printf("\n1.Insert 2.Search 3.Display 4.Exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                int id;
                char title[20];
                char author[20];
                float price;

                printf("Enter the id,title,author,price\n");
                scanf("%d%s%s%f",&id,title,author,&price);

                insert(id,author,title,price);

                break;
            }

            case 2:
            {
                char name[20];
                int result;

                printf("Enter the Title\n");
                scanf("%s",name);

                /* Sort before binary search */
                sort();

                result=search(0,size-1,name);

                if(result!=-1)
                {
                    printf("%s is found at %d\n",name,result);
                }
                else
                {
                    printf("Book not found\n");
                }

                break;
            }

            case 3:
                display(size);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Input\n");
        }

    }while(choice!=4);

    free(b);

    return 0;
}

