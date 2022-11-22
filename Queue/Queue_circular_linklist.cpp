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
    if (rear == NULL)
    {
        front = rear = newnode;
        rear->next = front;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        newnode->next = front;
    }
}
void dequeue()
{
    struct node *temp;
    temp = front;
    if (front == NULL && rear == NULL)
    {
        cout << "Queue is empty !";
    }
    else if (front == rear)
    {
        cout << "The " << front->data << " has been removed" << endl;
        front = rear = NULL;
        free(temp);
    }
    else
    {
        cout << "The " << front->data << " has been removed" << endl;
        front = front->next;
        rear->next = front;
        free(temp);
    }
}
void display()
{
    struct node *temp;
    temp = front;
    if (front == NULL && rear == NULL)
    {
        cout << "Queue is empty";
    }
    else
    {
        cout << "Queue: ";
        while (temp != rear)
        {
            cout << temp->data << ",";
            temp = temp->next;
        }
        cout << rear->data << endl;
    }
}
int main()
{
    enqueue(1);
    enqueue(4);
    enqueue(4);
    enqueue(6);
    display();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    display();
    return 0;
}

/*
 OUTPUT:
 Queue: 1,4,4,6
 The 1 has been removed
 The 4 has been removed
 The 4 has been removed
 The 6 has been removed
 Queue is empty */
