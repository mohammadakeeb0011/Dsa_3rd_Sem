#include<stdio.h>
#include<stdlib.h>
typedef struct Arr
{
    int *A;
    int size;
    int length;
}Array;

void swap(int *i,int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}
void display(Array a)
{
    for(int i=0;i<a.length;i++)
        printf("%d ",a.A[i]);
}
int append(Array *a,int x)
{
    if(a->length < a->size){
    a->A[a->length++]=x;
    return 1;
    }
    else return -1;
}
int insert(Array *a,int index, int x)
{   if(0<=index && index<=a->length )
    {
    for(int i = a->length; i > index ; i--)
        a->A[i] = a->A[i-1];
    a->A[a->length++] = x;
    return 1;
    }
    else return -1;
}
int del(Array *a,int index)
{
    if(0 <= index && index < a->length)
    {
    int i;
    int x = a->A[index];
    for(i=index; i < (a->length - 1); i++)
    {
        a->A[i] = a->A[i+1];
    }
    a->length--;
    return x;
    }
    return 0;
}
int search(Array a,int key)
{
    int i;
    for(i=0; i < a.length; i++)
    {
        if(a.A[i] == key)
        return i;
    }
    return -1;
}
void set(Array *a,int index, int x)
{
    if(0 <= index && index < a->length)
    a->A[index] = x;
}
int bisearch(Array a,int key)
{
    int l=0;
    int h = a.length-1;
    while(l<=h)
    {
        int m = (l+h)/2;
        if(key == a.A[m])   
            return m;
        else if(key < a.A[m])   
            h = m - 1;
        else 
            l = m + 1;
    }
    return -1;
}
int Rbisearch(Array a,int l,int h,int key)
{
    int mid;
    if(l<=h)
    {
        mid = (l+h)/2;
        if(a.A[mid] == key)
            return mid;
        else if(a.A[mid] < key)
            return Rbisearch(a,mid+1,h,key);
        else
            return Rbisearch(a,l,mid+1,key);
    }
    return -1; 
}
int max(Array a)
{
    int i,x = a.A[0];
    for(i=1;i<a.length;i++)
    {
        if(x > a.A[i])
        {
            x = a.A[i];
        }
    }
    return x;
}
int min(Array a)
{
    int i,x = a.A[0];
    for(i=1;i<a.length;i++)
    {
        if(x < a.A[i])
        {
            x = a.A[i];
        }
    }
    return x;
} 
long sum(Array a)
{
    int i;
    long sum = 0;
    for(i=0; i<a.length; i++)
        sum += a.A[i];
    return sum;
}
int avg(Array a)
{
    int i;
    long sum = 0;
    for(i=0; i<a.length; i++)
        sum += a.A[i];
    return sum/a.length;
}
void reverse(Array *a)
{
    int i,j,temp;
    for(i=0,j=a->length-1; i<j ; i++,j--)
    {
        temp = a->A[j];
        a->A[j] = a->A[i];
        a->A[i] = temp;
    }
}
void leftshift(Array *a,int offset)
{   
    int i;
    while(offset)
    {
    for(i=0; i<a->length; i++)
    {
        a->A[i] = a->A[i+1];
    }
    offset--;
    a->length--;
    }
}
void rightshift(Array *a,int offset)
{   
    int i;
    while(offset)
    {
    for(i=a->length-1; i>0; i--)
    {
        a->A[i] = a->A[i-1];
    }
    a->A[0]=0;
    offset--;
    a->length++;
    }
}
int Get(Array a,int index)
{
    if(0 <= index && index < a.length)
    return a.A[index];
    else
    return 0;
}
int issorted(Array a)
{
    int i;
    for(i=0; i<a.length ; i++)
    {
        if(a.A[i]>a.A[i+1])
            return 0;
    }
    return 1;
}
void sinsert(Array *a,int x)
{
    int i =a->length -1;
    while(a->A[i]>x)
    {
        a->A[i+1] = a->A[i];
        i--;
    }
    a->A[i+1] = x;
    a->length++;
}
void negpos(Array *a)
{
    int i = 0;
    int j = a->length - 1;
    while(i<j)
    {
    while(a->A[i]<0){i++;}
    while(a->A[j]>=0){j--;}
    if(i<j)
    swap(&a->A[i],&a->A[j]);
    }
}
Array* merge(Array a,Array b)
{
    int i,j,k=0;
    i=j=k;
    Array *c = (Array*)malloc(sizeof(Array));
    while(i<a.length && j<b.length)
    {
    if(a.A[i]<b.A[j])
        c->A[k++]=a.A[i++];
    else
        c->A[k++]=b.A[j++];
    }
    for(;i<a.length;i++)
        c->A[k++]=a.A[i++];
    for(;j<b.length;j++)
        c->A[k++]=b.A[j++];
    c->length = a.length + b.length;
    return c;
}
Array* Union(Array a,Array b)
{
    int i,j,k=0;
    i=j=k;
    Array *c = (Array*)malloc(sizeof(Array));
    while(i<a.length && j<b.length)
    {
    if(a.A[i]<b.A[j])
        c->A[k++]=a.A[i++];
    else if(a.A[i]>b.A[j])
        c->A[k++]=b.A[j++];
    else    
        {
            c->A[k++]=a.A[i++];
            j++;
        }
    }
    for(;i<a.length;i++)
        c->A[k++]=a.A[i++];
    for(;j<b.length;j++)
        c->A[k++]=b.A[j++];
    c->length = k;
    return c;
}
Array* Intersection(Array a,Array b)
{
    int i,j,k=0;
    i=j=k;
    Array *c = (Array*)malloc(sizeof(Array));
    while(i<a.length && j<b.length)
    {
    if(a.A[i]<b.A[j])
        i++;
    else if(a.A[i]>b.A[j])
        j++;
    else    
        {
            c->A[k++]=a.A[i++];
            j++;
        }
    }
    c->length = k;
    return c;
}
Array* Difference(Array a,Array b)
{
    int i,j,k=0;
    i=j=k;
    Array *c = (Array*)malloc(sizeof(Array));
    while(i<a.length && j<b.length)
    {
    if(a.A[i]<b.A[j])
        c->A[k++]=a.A[i++];
    else if(a.A[i]>b.A[j])
        j++;
    else    
        i++,j++;
    }
    for(;i<a.length;i++)
        c->A[k++]=a.A[i++];
    c->length = k;
    return c;
}


int main()
{
    Array arr1;
    int ch;
    int x,index;
    printf("Enter Size of an Array");
    scanf("%d",&arr1.size);
    arr1.A = (int *)malloc(arr1.size*sizeof(int));
    arr1.length=0;
do
{
    printf("\n\nMenu\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Sum\n");
    printf("5. Display\n");
    printf("6.Exit\n");
    printf("enter you choice ");
    scanf("%d",&ch);
switch(ch)
{
case 1: printf("Enter an element and index");
        scanf("%d%d",&x,&index);
        insert(&arr1,index,x);
        break;
case 2: printf("Enter index ");
        scanf("%d",&index);
        x=delete(&arr1,index);
        printf("Deleted Element is %d\n",x);
        break;
case 3:printf("Enter element to search ");
        scanf("%d",&x);
        index=LinearSearch(&arr1,x);
        printf("Element index %d",index);
        break;
case 4:printf("Sum is %d\n",Sum(arr1));
        break;
case 5:Display(arr1);
}
}while(ch<6);
    return 0;
}