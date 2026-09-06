#include<stdio.h>
#include<stdlib.h>
int *a;
int sum(int i ,int n)
{
    if(i==n)
    {
        return 0;
    }
    return a[i]+sum(i+1,n);
}
int max(int i,int n,int *large)
{  
    if(i==n)
        return *large;
    if(a[i]>*large)
    {
        *large=a[i];
    }
    return max(i+1,n,large);
}
int min(int i,int n,int *small)
{  
    if(i==n)
        return *small;
    if(a[i]<*small)
    {
        *small=a[i];
    }
    return min(i+1,n,small);
}
int counteven(int i,int n)
{
    if(i==n)
        return 0;

    if((a[i] & 1) == 0)
        return 1 + counteven(i+1,n);

    return counteven(i+1,n);
}
int main()
{  printf("Enter the size of the array\n");
   int n;
   scanf("%d",&n);
    a=(int *)calloc(n,sizeof(int));
   printf("Enter the Elements of array\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
   printf("Sum of all elements:%d\n",sum(0,n));
   printf("Maximum Element:%d\n",max(0,n,a));
   printf("Min Element:%d\n",min(0,n,a));
   printf("No.of Even Elements:%d\n",counteven(0,n));
   free(a);
   return 0;
   
}