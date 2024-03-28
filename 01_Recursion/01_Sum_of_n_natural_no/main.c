#include<stdio.h>
//Using recursion
int sum(int n)
{
    if(n==0) return 0;
    return sum(n-1) + n;
}

//using loop
int sum2(int n)
{
    int s = 0;
    for(int i =1; i<=n ; i++)
    {
        s = s + i;
    }
    return s;
}

//Using formula
int sum3(int n)
{
    return n*(n+1)/2;
}

int main()
{
    printf("%d\n",sum(10));
    printf("%d\n",sum2(10));
    printf("%d\n",sum3(10));
    return 0;
}