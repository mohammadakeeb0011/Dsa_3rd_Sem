#include<stdio.h>

//using recursion
float e(int x,int n)
{
    static float p=1, f=1;
    float r;
    if(n==0) return 1;
    else
    {
        r =e(x,n-1);
        p = p*x;
        f = f*n;
        return (r + (p/f));
    }
}
//using loop
float e2(float x,int n)
{
    float s = 1.0;
    for(;n>0 ; n--)
    {
        s = 1 + x/n*s;
    }
    return s;
}
//using recursion
float e3(float x,int n)
{
    static float s = 1.0;
    if(n==0) return s;
    s = 1 + x/n*s;

    return e3(x,n-1);
}

int main()
{
    printf("%f\n",e(1,100));
    printf("%f\n",e2(1.0,100));
    printf("%f\n",e3(1.0,100));
    return 0;
}