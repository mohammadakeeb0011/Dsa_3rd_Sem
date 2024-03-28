#include<stdio.h>

//using loop
int fact(int n)
{
    int f = 1;
    for(int i =1; i<=n ; i++)
    {
        f = f * i;
    }
    return f;
}

//simple
int c1(int n , int r)
{
    int t1 , t2, t3;
    t1 = fact(n);
    t2 = fact(r);
    t3 = fact(n-r);

    return t1/(t2*t3);
}

//Using recursion
int c(int n, int r)
{
    if(n==r || r==0) return 1;

    return c(n-1,r-1) + c(n-1,r);
}

int main()
{
    printf("%d\n",c1(4,2));
    printf("%d\n",c(4,2));
    return 0;
}