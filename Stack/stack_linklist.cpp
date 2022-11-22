#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *link;
};
struct node *top = 0;
void push(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->link = top;
    top = newnode;
}
void display()
{
    struct node *temp;
    temp = top;
    if (temp == 0)
    {
        cout << "stack underflow";
    }
    else
    {
        while (temp != 0)
        {
            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << endl;
    }
}
void peek()
{
    if (top != 0)
    {
        cout << "top most element is :" << top->data << endl;
    }
}
void pop()
{
    struct node *temp;
    temp = top;
    if (top == 0)
    {
        cout << "Stack underflow";
    }
    else
    {
        top = temp->link;
        free(temp);
    }
}
int main()
{
    push(4);
    push(6);
    push(5);
    display();
    pop();
    display();
    peek();
    return 0;
}