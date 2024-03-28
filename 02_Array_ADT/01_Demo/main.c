#include<stdio.h>

typedef struct A
{
    int *A;
    int size;
    int length;
}Array;

void display(Array arr)
{
    int i;
    printf("\nElements are:\n");
    for(i=0; i<arr.length ; i++)
        printf("%d ",arr.A[i]);
}
int main()
{
    Array arr;
    int n,i;
    printf("Enter size of an array");
    scanf("%d",&arr.size);
    arr.A= (int*)malloc(arr.size*sizeof(int));
    arr.length = 0;
    printf("Enter number of numbers");
    scanf("%d",&n);
    printf("Enter all elements");
    for(i=0; i<n ; i++)
        scanf("%d",&arr.A[i]);
    arr.length = n;
    return 0;
}