#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
int data;
struct node *next;
}Node;

Node* first=NULL;

// ---------------------------CREAT FUN-------------------------

void create(int A[],int n)
{
int i;
Node *t,*last;
first=(Node *)malloc(sizeof( Node));
first->data=A[0];
first->next=NULL;
last=first;
for(i=1;i<n;i++)
{
t=(Node*)malloc(sizeof(Node));
t->data=A[i];
t->next=NULL;
last->next=t;
last=t;
}
}

// ------------------------DISPLAY FUN--------------------------

void Display(Node *p)
{
    printf("\n");
while(p!=NULL)
{
printf("%d ",p->data);
p=p->next;
}
printf("\n");
}

// --------------------RECURSIVE DISPLAY FUN--------------------

void RDisplay(Node *p)
{
if(p!=NULL)
{
RDisplay(p->next);
printf("%d ",p->data);
}
}

// ------------------------COUNT FUN----------------------------

int count(Node *p)
{
    int l=0;
    while(p)
    {
        l++;
        p = p->next;
    }
    return l;
}

// ---------------RECURSIVE COUNT FUN----------------------------

int Rcount(Node *p)
{
    if(p!=NULL)
        return Rcount(p->next)+1;
    else
        return 0;
}

// -----------------------------SUM FUN-------------------------

int sum(Node *p)
{
    int s=0;
    while(p!=NULL)
    {
        s+=p->data;
        p=p->next;
    }
    return s;
}

// ----------------------------RSUM FUN-------------------------

int Rsum(Node *p)
{
    if(p==NULL)
        return 0;
    else    
        return Rsum(p->next)+p->data;
}

// -----------------------------MAX FUN-------------------------

int Max(Node *p)
{
    int max = INT_MIN;
    while(p)
    {
        if(p->data>max)
            max=p->data;
        p=p->next;
    }
    return max;
}

// -----------------------------RMAX FUN-------------------------

int RMax(Node *p)
{
    int x=0;
    if(p==0)
        return INT_MIN;
    x=RMax(p->next);
    return x > p->data ? x : p->data;
}

// -----------------------------LSearch FUN-------------------------

Node* LSearch(Node* p, int key)
{
    while(p!=NULL)
    {
        if(key==p->data)
            return p;
        p=p->next;
    }
    return NULL;
}

// -----------------------------RSearch FUN-------------------------

Node* RSearch(Node* p, int key)
{
    if(p!=NULL)
        return NULL;
    if(key==p->data)
        return p;
    return RSearch(p->next,key);
}

// -----------------------------LSearch FUN-------------------------

Node* MLSearch(Node* p, int key)
{
    Node *q;
    while(p!=NULL)
    {
        q=p;
        if(key==p->data)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        p=p->next;
    }
    return NULL;
}

// -----------------------------INSERT FUN-------------------------

void Insert(Node *p, int index,int x)
{
    if(index < 0 || index > count(p))
        return;
    Node *t = (Node *)malloc(sizeof(Node));
    t->data = x;
    int i;
    if(index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for(i=0; i<index-1;i++)
            p=p->next;
        t->next = p->next;
        p->next = t;
    }
    
}

// -------------------------SortedINSERT FUN-------------------------

void SortedInsert(Node* p, int x)
{
    Node *t,*q=NULL;

    t=(Node *)malloc(sizeof(Node));
    t->data = x;
    t->next = NULL;

    if(first == NULL)
        first = t;
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=first;
            first=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }
}

// -------------------------Delete FUN-------------------------

int Delete(Node *p,int index)
{
    Node *q=NULL;
    int x=-1;

    if(index < 1 || index > count(p))
        return -1;
    if(index == 1)
    {
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }
    else
    {
        for(int i=0;i < index-1; i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }
}


int isSorted(Node *p)
{
int x=-65536;
while(p!=NULL)
{
if(p->data < x)
return 0;
x=p->data;
p=p->next;
}
return 1;
}



void RemoveDuplicate(Node *p)
{
Node *q=p->next;
while(q!=NULL)
{
if(p->data!=q->data)
{
p=q;
q=q->next;
}
else
{
p->next=q->next;
free(q);
q=p->next;
}
}
}

void Reverse1(struct Node *p)
{
int *A,i=0;
struct Node *q=p;
A=(int *)malloc(sizeof(int)*count(p));
while(q!=NULL)
{
A[i]=q->data;
q=q->next;
i++;
}
q=p;
i--;
while(q!=NULL)
{
q->data=A[i];
q=q->next;
i--;
}
}
void Reverse2(struct Node *p)
{
struct Node *q=NULL,*r=NULL;
while(p!=NULL)
{
r=q;
q=p;
p=p->next;
q->next=r;
}
first=q;
}
void Reverse3(struct Node *q,struct Node *p)
{
if(p)
{
Reverse3(p,p->next);
p->next=q;
}
else
first=q;
}



void Merge(Node *p,Node *q)
{
Node *last,*third;
if(p->data < q->data)
{
third=last=p;
p=p->next;
third->next=NULL;
}
else
{
third=last=q;
q=q->next;
third->next=NULL;
}
while(p && q)
{
if(p->data < q->data)
{
last->next=p;
last=p;
p=p->next;
last->next=NULL;
}
else
{
last->next=q;
last=q;
q=q->next;
last->next=NULL;
}
}
if(p)last->next=p;
if(q)last->next=q;
}



int isLoop(struct Node *f)
{
struct Node *p,*q;
p=q=f;
do
{
p=p->next;
q=q->next;
q=q?q->next:q;
}while(p && q && p!=q);
if(p==q)
return 1;
else
return 0;
}







int main()
{
int A[]={3,5,7,10,25,8,32,2};
create(A,8);
Display(first);
printf("\nLength is %d\n",count(first));
printf("\nSum is %d\n",Rsum(first));
printf("\nMax is %d\n",RMax(first));
return 0;
}