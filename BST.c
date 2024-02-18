#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};
struct node *root = NULL;

void Insert(int x)
{
    struct node *newnode, *temp, *p;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->rchild = NULL;
    newnode->lchild = NULL;
    if (root == NULL)
    {
        printf("Root created ");
        root = newnode;
    }

    temp = root;
    // moving to pos
    while (temp != NULL)
    {
        printf("loop run ");
        p = temp;
        if (temp->data > x)
        {
            printf("r child ");
            temp = temp->lchild;
        }
        else if (temp->data < x)
        {
            temp = temp->rchild;
        }
        else
        {
            return;
        }
    }
    if (p->data < x)
    {
        p->rchild = newnode;
    }
    else
    {
        p->lchild = newnode;
    }
}

void Inorder(struct node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf(" %d ", p->data);
        Inorder(p->rchild);
    }
}
int main()
{
    Insert(10);
    Insert(20);
    Insert(8);
    Insert(30);
    Insert(5);
    Inorder(root);
    return 0;
}