#include<stdio.h>
#include<stdlib.h>

typedef struct s{
    int size;
    int top;
    int* S;
}Stack;
void create(Stack *st)
{
    printf("Enter the sizeof stack: ");
    scanf("%d", &st->size);      // Getting size
    // Declearing an array of required size
    st->S = (int*)malloc(sizeof(int)* st->size);
    st->top = -1;
}
void push(Stack * st, int x)
{
    if(st->top == st->size-1)
    {
        printf("\n----------ERROR: Stack overflow----------\n");
        EXIT_FAILURE;
    }
    else
    {
       st->S[++st->top] = x;
    }
}
int pop(Stack * st)
{
    if(st->top == -1)
    {
        printf("\n----------ERROR: Stack underflow----------\n");
        EXIT_FAILURE;
    }
    else
    {
        int x = st->S[st->top--];
        return x;
    }
}
void display(Stack st)
{   
    for(int i = st.top; i >= 0; i--)
    {
        printf("%d ", st.S[i]);
    }
    printf("\n");
}
int isempty(Stack st)
{
    if(st.top == -1)
        return 1;
    return 0;
}
int isfull(Stack st)
{
    if(st.top == st.size-1)
        return 1;
    return 0;
}
int top(Stack st)
{
    if(!isempty(st))
        return st.S[st.top];
    return -1;
}
int peek(Stack st,int index)
{
    if(st.top-index+1 < 0)
    {
        printf("Invalid position.");
        return -1;
    }
        return st.S[st.top - index + 1];
}

int main()
{
    Stack st;
    
    return 0;
}