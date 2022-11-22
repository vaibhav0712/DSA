#include <iostream>
#include <stdio.h>
#include "Queue.h"
using namespace std;
class Tree
{
public:
    Node *root;
    Tree() { root = NULL; }
    void CreatTree();
    void Preorder(Node *p);
    void Postorder(Node *p);
    void Inorder(Node *p);
    void Levelorder(Node *p);
    int Height(Node *root);
    int CountNode(Node *p);
    int leafNode(Node *p);
    int Search(Node *p, int key);
};
void Tree::CreatTree()
{
    Node *p, *t;
    int x;
    Queue q(100);
    printf("Enter root value :");
    scanf("%d", &x);
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);

    while (!q.isEmpty())
    {
        p = q.dequeue();
        printf("Enter left child of %d : ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        printf("Enter right child of %d : ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}
void Tree::Preorder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Tree::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
    cout << endl;
}
void Tree::Postorder(Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << " ";
    }
    cout << endl;
}
void Tree::Levelorder(Node *p)
{
    Queue q2(100);
    cout << p->data;
    q2.enqueue(p);
    while (!q2.isEmpty())
    {
        p = q2.dequeue();
        if (p->lchild)
        {
            cout << p->lchild->data << " ";
            q2.enqueue(p->lchild);
        }
        if (p->rchild)
        {
            cout << p->rchild->data << " ";
            q2.enqueue(p->rchild);
        }
    }
}
int Tree::CountNode(Node *p)
{
    int x, y;
    if (p)
    {
        x = CountNode(p->lchild);
        y = CountNode(p->rchild);
        return x + y + 1;
    }
    return 0;
}
int Tree::Height(Node *root)
{
    int x, y;
    if (root == 0)
    {
        return 0;
    }
    x = Height(root->lchild);
    y = Height(root->rchild);
    if (x > y)
    {
        return x + 1; // only count left nodes
    }
    else
    {
        return y + 1; // only count right nodes
    }
}
int Tree::leafNode(Node *p)
{
    int x, y;
    if (p)
    {
        x = leafNode(p->lchild);
        y = leafNode(p->rchild);
        if (p->lchild == NULL && p->rchild == NULL)
        {
            return x + y + 1; // will count leaf node
        }
        else
        {
            return x + y; // 0
        }
    }
    return 0;
}
// int Tree::Search(Node *p, int key)
// {
//     while (p != NULL)
//     {
//         if (p->data == key)
//         {
//             cout << "key found ! ";
//             return key;
//         }
//         else if (p->data > key)
//         {
//             p = p->lchild;
//         }
//         else if (p->data < key)
//         {
//             p = p->rchild;
//         }
//     }
//     return 0;
// }

int main()
{
    Tree t;
    t.CreatTree();
    cout << "Preorder : ";
    t.Preorder(t.root);
    cout << "\nPostorder : ";
    t.Levelorder(t.root);
    cout << "\nThe number of Node's : " << t.CountNode(t.root);
    cout << "\nThe height of tree : " << t.Height(t.root);
    cout << "\nThe number of leafNode's : " << t.leafNode(t.root);
    // cout << "\n The number you want : " << t.Search(t.root, 25);// only work for BST

    return 0;
}