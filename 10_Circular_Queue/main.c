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
    q->rear=q->front=0;
    q->Q=(int*)malloc(sizeof(int)*q->size);
}

void enqueue(Queue* q, int x)
{
    if((q->rear + 1)%q->size == q->front)
        printf("ERROR: Queue is full!\n");
    else
        q->rear = (q->rear + 1)%q->size;
        q->Q[q->rear] = x;
}

int dequeue(Queue* q)
{
    int x =-1;
    if(q->front == q->rear)
        printf("ERROR: Queue is empty!\n");
    else
    {
        q->front = (q->front + 1)%q->size;
        x = q->Q[q->front];
    }
    return x;
}

// void display(Queue q)
// {
//     for(int i = q.front + 1; i<=q.rear; i = (i+1)%q.size)
//     {
//         printf("%d ", q.Q[i]);
//     }
//     printf("\n");
// }
void display(Queue q)
{
    int i = q.front + 1;
    do
    {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);
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
    if((q.rear + 1)%q.size == q.front)
        return 1;
    return 0;
}

int search(Queue q, int k)
{
    int n,i = q.front + 1;
    n=0;
    do
    {   n++;
        if(k == q.Q[i])
            return n;
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);
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
    dequeue(&qu);
    display(qu);
    dequeue(&qu);
    display(qu);
    dequeue(&qu);
    display(qu);
    printf("The element 40 is at index %d\n", search(qu, 20));
    return 0;
}