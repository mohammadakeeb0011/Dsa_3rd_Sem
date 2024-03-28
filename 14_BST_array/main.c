#include <stdio.h>
#include <stdlib.h>
void insert(int* tree, int size, int element)
{
    if (tree == NULL)
        return;
int pos = 0;
while (pos < size)
{
 if (tree[pos])
        {
            if (tree[pos] < element)
                pos = 2 * pos + 2;  // right
            else if (tree[pos] && tree[pos] > element)
                pos = 2 * pos + 1;  // left
        }
        else
        {
            tree[pos] = element;
            return;
        }
    }
}
void print(int* tree, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", tree[i]);
    printf("\n");
}
int main()
{
    int tree[100] = {0};
    const int tsize = 100;
    print(tree, 20);
    insert(tree, tsize, 2);
    insert(tree, tsize, 3);
    insert(tree, tsize, 5);
    insert(tree, tsize, 1);
    insert(tree, tsize, 4);
    print(tree, 20);
    return 0;
}