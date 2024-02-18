#include <iostream>
using namespace std;
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
} *root = NULL;

void Insert(int key)
{
    struct node *t = root;
    struct node *r, *p;
    p = new node;
    p->data = key;
    p->lchild = p->rchild = NULL;
    if (root == NULL)
    {
        root = p;
    }
    t = root;
    while (t != NULL) // go to that pos
    {
        r = t;
        if (key < t->data)
        {
            t = t->lchild;
        }
        else if (key > t->data)
        {
            t = t->rchild;
        }
        else
        {
            return;
        }
    }
    if (key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}
void Inorder(struct node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}
void Search(struct node *p, int key) //
{
    while (p != NULL)
    {
        if (p->data == key)
        {
            cout << "Key Found " << p->data;
            return; // its important to exit from the function
        }
        else if (p->data > key)
        {
            p = p->lchild;
        }
        else if (p->data < key)
        {
            p = p->rchild;
        }
        else
        {
            cout << "Key Not Found !";
        }
    }
}
int main()
{
    Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);
    Insert(30);

    Inorder(root);
    Search(root, 8);
    return 0;
}