#include<stdio.h>
#include<stdlib.h>

typedef struct n
{
    struct n *prev;
    int data;
    struct n *next;
}Node;
Node* first;

void create(int A[], int n)
{
    int i;
    Node *t,*last;

    first = (Node*)malloc(sizeof(Node));
    first->data=A[0];
    first->next=first->prev=NULL;
    last=first;

    
    for ( i = 1; i < n; i++)
    {
        t = (Node*)malloc(sizeof(Node));
        t->data=A[i];
        t->next=NULL;
        t->prev = last;
        last->next=t;
        last = t;
    }
    
}

void display(Node *p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int length(Node* p)
{
    int i = 0;
    for( ; p ; i++)
     p=p->next;
    return i;
}

int insert(Node* p, int index, int x)
{
    if(0<=index && index<= length(first))
    {
        Node* t;
            t = (Node*)malloc(sizeof(Node));
            t->data = x;
        if(index == 0)
        {
            t->next = first;
            first->prev = t;
            first = t; 
        }
        else
        {
            for(int i = 1 ; i<index; i++)
            p=p->next;
            t->next= p->next;
            p->next=t;
        }
        return 1;
    }
    return 0;
}

int delete(Node* p, int index)
{
    if(0<=index && index< length(first))
    {
        int x;
        if(index == 0)
        {
            x = first->data;
            first = first->next;
            free(p); 
        }
        else
        {
            Node* q;
            for(int i = 0 ; i<index; i++)
            {
                q=p;
                p=p->next;
            }
            q->next= p->next;
            x = p->data;
            free(p);
        }
        return x;
    }
}

int search(Node* p,int key)
{
    int i=0;
    while(p!= NULL)
    {
        if(p->data == key)
        return i;
        p=p->next;
        i++;
    }
    return -1;
}