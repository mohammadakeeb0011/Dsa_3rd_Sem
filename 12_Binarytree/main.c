#include<stdio.h>
#include<stdlib.h>
struct node
{
int data_element;
struct node *left, *right;
};
struct node *new_node(int data_element)
{
struct node *temp = (struct node *)malloc(sizeof(struct node)); 
temp->data_element = data_element;
temp->left = temp->right = NULL;
return temp;
}
void display(struct node *root) 
{
if (root != NULL)
{
display(root->left);
printf("%d \n", root->data_element);
display(root->right);
}
}
struct node* insert(struct node* node, int data_element) 
{
if (node == NULL) return new_node(data_element);
if (data_element < node->data_element)
{
node->left = insert(node->left, data_element);
}
else if (data_element > node->data_element)
{
node->right = insert(node->right, data_element);
}
return node;
}
int main()
{
struct node *root = NULL;
root = insert(root, 10);
insert(root, 20);
insert(root, 30);
insert(root, 40);
insert(root, 50);
insert(root, 60);
insert(root, 70);
display(root); 
return 0;
}