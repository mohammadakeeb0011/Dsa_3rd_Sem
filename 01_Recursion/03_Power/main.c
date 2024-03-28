#include<stdio.h>
//Using recursion
int pow1(int m,int n)
{
    if(n==0) return 1;
    return pow1(m,n-1)*m;
}

//Using formula
int pow2(int m, int n)
{
    if(n==0) return 1;
    if(n%2 == 0) return pow2(m*m,n/2);
    else
    return m*pow2(m*m, (n-1)/2);
}

//Using loop
int pow3(int m, int n)
{
    int p = 1;
    for(int i=1; i<=n; i++)
    {
        p *=2;
    }
    return p;
}

int main()
{
    printf("%d\n",pow1(2,5));
    printf("%d\n",pow2(2,5));
    printf("%d\n",pow3(2,5));
    return 0;
}