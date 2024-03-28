#include<stdio.h>

void TOH(int n, int a,int b,int c)
{
    if(n > 0)
    {
        TOH(n-1,a,c,b);
        printf("From %d to %d\n",a,c);
        TOH(n-1,b,a,c);
    }
}

int main()
{
    TOH(3,1,2,3);
    printf("\n-----------------------\n");
    TOH(5,1,2,3);
    return 0;
}