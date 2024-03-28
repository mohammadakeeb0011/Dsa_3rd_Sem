#include<iostream>
#include<cstdlib>
using namespace std;

class Node 
{
    public:
        char data;
        struct Node* next;
        Node():next(nullptr){};
};

class Stack
{
    private:
        Node* top;
    public:
        Stack(): top(nullptr){};
        void push(char x);
        void display();
        char pop();
        char stacktop();
        int isEmpty();
        ~Stack(){delete top;};
};

void Stack::push(char x)
{
    Node* t;
    t = (Node*)malloc(sizeof(Node));
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
void Stack::display()
{
    Node* p =  top;
    while(p)
    {
        cout<< p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
char Stack::pop()
{
    Node* t;
    char x = -1;
    if(top == NULL)
        cout<<"Stack is empty."<<endl;
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}
char Stack::stacktop()
{
    char x=-1;
    if(top==NULL)
        cout<<"Stack is empty."<<endl;
    else
    {
        Node* t;
        t = top;
        x = t->data;
    }
    return x;
}
int Stack::isEmpty()
{
    if(top == nullptr)
        return 1;
    return 0;
}
int outstackpre(char op)
{
    if(op == '+' || op == '-')
        return 1;
    else if(op == '*' || op == '/')
        return 3;
    else if(op == '^')
        return 6;
    else if(op == '(')
        return 7;
    return 0;
}
int instackpre(char op)
{
    if(op == '+' || op == '-')
        return 2;
    else if(op == '*' || op == '/')
        return 4;
    else if(op == '^')
        return 5;
    else if(op == '(')
        return 0;
    return 0;
}
int isoperand(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')')
        return 0;
    return 1;
}
int isbalanced(char* expression)
{
    int i;
    Stack st;
    for(i=0; expression[i] != '\0'; i++)
    {
        if(expression[i] == '(')
            st.push(expression[i]);
        else if(expression[i] == ')')
            if(!st.isEmpty())
                st.pop();
            else
                return 0;

    }
    return 1;
     
}

int main()
{
    char* exp ="((a+b)*c-d))";

    if(isbalanced(exp))
        cout<<"Expression is balanced"<<endl;
    else    
        cout<<"Expression is not balanced"<<endl;
    return 0;
}