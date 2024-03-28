#include<stdio.h>
#include<stdlib.h>

 struct Node 
{
    int data;
    struct Node* next;
};

struct Node* top=NULL;

void push(int x)
{
    struct Node* t;
    t = (struct Node*)malloc(sizeof(struct Node));
    if(t==NULL)
        printf("Stack is full");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
        t = NULL;
    }   
}
void display()
{
    struct Node* p =  top;
    while(p)
    {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

int pop()
{
    struct Node* t;
    int x = -1;
    if(top == NULL)
        printf("Stack is empty.");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

int sttop()
{
    int x=-1;
    if(top==NULL)
        printf("Stack is empty");
    else
    {
        struct Node* t;
        t = top;
        x = t->data;
    }
    return x;
}

int main()
{
    
    return 0;
}