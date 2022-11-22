#include <iostream>
using namespace std;
// using array
#define N 5
int queue[N];
int front = -1;
int rear = -1;
void enqueueR(int x)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}
void enqueueL(int x)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        front--;
        queue[front] = x;
    }
}
void dequeueL()
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is empty ";
    }
    else if (front == rear)
    {
        cout << "The " << queue[front] << " has been removed from Left" << endl;
        front = rear = -1;
    }
    else
    {
        cout << "The " << queue[front] << " has been removed from Left" << endl;
        front++;
    }
}
void dequeueR()
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is empty ";
    }
    else if (front == rear)
    {
        cout << "The " << queue[front] << " has been removed from Right " << endl;
        front = rear = -1;
    }
    else
    {
        cout << "The " << queue[rear] << " has been removed from Right " << endl;
        rear--;
    }
}
void display()
{
    int temp = front;
    if (front == -1 && rear == -1)
    {
        cout << "Queue is empty!";
    }
    else
    {
        cout << "Queue : ";
        while (temp != rear)
        {
            cout << queue[temp] << " ";
            temp++;
        }
        cout << queue[rear] << endl;
    }
}
int main()
{

    enqueueR(4);
    enqueueR(7);
    enqueueR(5);
    enqueueR(7);
    display();
    dequeueL();
    enqueueL(8);
    enqueueL(6);
    enqueueR(2);
    display();
    dequeueR();
    display();
    return 0;
}