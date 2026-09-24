#include<stdlib.h>
#include <stdio.h>
int process(int *a,int n)
{
    int stack[n];
    int top=-1,freq=0;

    for(int i=0;i<n;i++)
    {
        if(a[i]>=0)
        {
            stack[++top]=a[i];
            freq++;
        }
        else
        {
            if(freq<5)
            {
                printf("Error\n");
                return 0;
            }
            else
            {
                int i=5;

                while(i>0)
                {
                    printf("%d ",stack[top--]);
                    freq--;
                    i--;
                }
            }
        }
    }

    if(top!=-1)
    {
        for(int i=0;i<=top;i++)
        {
            printf("%d ",stack[i]);
        }
    }

    return 0;
}
int main() {
printf("Enter the no of elements\n");
    int n;
    scanf("%d",&n);
    int *a=(int *)malloc(n*sizeof(int));

printf("Enter the array elements\n");
    for(int i=0;i<n;i++)
        {
            scanf("%d",a+i);
        }
    printf("Array After Processed\n");
    process(a,n);
    return 0;
}