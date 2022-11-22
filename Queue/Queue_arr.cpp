#include <iostream>
using namespace std;
#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if (rear == N - 1)
    {
        cout << "Queue is overflow" << endl;
    }
    else if (front == -1 && rear == -1)
    {
        front++;
        rear++;
        queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is empty";
    }
    else if (front == rear)
    {
        cout << "The " << queue[front] << " has been removed" << endl;
        front = rear = -1;
    }
    else
    {
        cout << "The " << queue[front] << " has been removed" << endl;
        front++;
    }
}
void display()
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is empty";
        exit(0);
    }
    for (int i = front; i <= rear; i++)
    {
        cout << queue[i] << ", ";
    }
    cout << endl;
}
void peek()
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is empty";
    }
    else
    {
        cout << "The front element is : " << queue[front] << endl;
    }
}
int main()
{

    enqueue(5);
    enqueue(7);
    enqueue(9);
    enqueue(1);
    enqueue(10);
    display();
    dequeue();
    dequeue();
    display();
    peek();
    return 0;
}