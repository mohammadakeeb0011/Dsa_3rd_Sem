#include<stdio.h>
//Using recursion
int fact(int n)
{
    if(n==0) return 1;
    return fact(n-1) * n;
}

//using loop
int fact2(int n)
{
    int f = 1;
    for(int i =1; i<=n ; i++)
    {
        f = f * i;
    }
    return f;
}

int main()
{
    printf("%d\n",fact(5));
    printf("%d\n",fact2(5));
    return 0;
}