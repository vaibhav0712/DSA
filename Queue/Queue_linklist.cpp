#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
void enqueue(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}
void display()
{
    if (front == NULL && rear == NULL)
    {
        cout << "Queue is empty !";
    }
    else
    {
        struct node *temp;
        temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}
void dequeue()
{
    if (front == NULL && rear == NULL)
    {
        cout << "Queue is empty !";
    }
    else if (front == rear)
    {
        struct node *temp;
        temp = front;
        front = rear = NULL;
        delete (temp);
    }
    else
    {
        struct node *temp;
        temp = front;
        front = front->next;
        delete (temp);
    }
}
void peek()
{
    if (front == NULL && rear == NULL)
    {
        cout << "Queue is empty !";
    }
    else
    {
        cout << "front : " << front->data << endl;
    }
}
int main()
{
    enqueue(3);
    enqueue(5);
    enqueue(8);
    enqueue(1);
    display();
    peek();
    dequeue();
    dequeue();
    dequeue();
    display();

    // dequeue();
    // display();
    return 0;
}