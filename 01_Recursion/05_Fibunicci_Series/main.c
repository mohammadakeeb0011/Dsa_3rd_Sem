#include<stdio.h>

//excessive recursive function
int fib(int n)
{
    if(n<=1) return n;
    return fib(n-2) + fib(n-1);
}

//Using loop
int fib2(int n)
{
    int t1 = 0, t2 = 1, s, i;
    if(n<=1) return n;
    for(i=2; i<=n ; i++)
    {
        s = t1 + t2;
        t1 = t2;
        t2 = s;
    }
    return s;
}

//using memorisation
int F[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int fib3(int n)
{
    if(n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if(F[n-2] == -1)
            F[n-2] = fib3(n-2);
        if(F[n-1] == -1)
            F[n-1] = fib3(n-1);
        return F[n-2] + F[n-1];
    }
}

int main()
{
    printf("%d\n",fib(6));
    printf("%d\n",fib2(6));
    printf("%d\n",fib3(6));
    return 0;
}