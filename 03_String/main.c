#include<stdio.h>

int len(char a[])
{
    int i;
    for(i=0;a[i] != '\0';i++){}
    return i;
}
char* lower(char a[])
{
    int i;
    for(i=0;a[i] != '\0';i++)
    {
        if(65 <= a[i] && a[i] <= 90)
            a[i] = a[i] + 32;
    }
    return a;
}
char* upper(char a[])
{
    int i;
    for(i=0;a[i] != '\0';i++)
    {
        if('a' <= a[i] && a[i] <= 'z')
            a[i] = a[i] - 32;
    }
    return a;
}
char* toggle(char a[])
{
    int i;
    for(i=0;a[i] != '\0';i++)
    {
        if('a' <= a[i] && a[i] <= 'z')
            a[i] = a[i] - 32;
        else if(65 <= a[i] && a[i] <= 90)
            a[i] = a[i] + 32;
    }
    return a;
}

int main()
{
    char name[] = "Akeeb";
    printf("Length of string = %d \n",len(name));
    printf("String in lower case = %s \n",lower(name));
    printf("String in upper case = %s \n",upper(name));
    char n[] = "Akeeb";
    printf("String in toggle case = %s \n",toggle(n));
    return 0;
}