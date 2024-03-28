#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int size;
    int front;
    int rear;
    int *Q;
}Queue;

void create(Queue* q, int size)
{
    q->size=size;
    q->rear=q->front=-1;
    q->Q=(int*)malloc(sizeof(int)*q->size);
}

void enqueue(Queue* q, int x)
{
    if(q->rear == q->size-1)
        printf("ERROR: Queue is full!\n");
    else
        q->Q[++(q->rear)] = x;
}

int dequeue(Queue* q)
{
    int x =-1;
    if(q->front == q->rear)
        printf("ERROR: Queue is empty!\n");
    else
    {
        x = q->Q[++(q->front)];
    }
    return x;
}

void display(Queue q)
{
    for(int i = q.front + 1; i<=q.rear; i++)
    {
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

int isempty(Queue q)
{
    if(q.rear == q.front)
        return 1;
    return 0;
}
int isfull(Queue q)
{
    if(q.rear == q.size -1)
        return 1;
    return 0;
}

int search(Queue q, int key)
{
    for(int i = q.front + 1; i<=q.rear; i++)
    {
        if(key == q.Q[i])
            return i;
    }
    return -1;
}
int main()
{
    Queue qu;
    create(&qu,6);
    enqueue(&qu, 10);
    enqueue(&qu, 20);
    enqueue(&qu, 30);
    enqueue(&qu, 40);
    enqueue(&qu, 50);
    display(qu);
    printf("The first element is %d\n", dequeue(&qu));
    printf("The element 40 is at index %d\n", search(qu, 40));
    display(qu);
    return 0;
}