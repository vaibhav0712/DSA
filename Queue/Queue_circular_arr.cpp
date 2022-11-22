#include <iostream>
using namespace std;
#define N 5
int front = -1;
int rear = -1;
int Queue[N];
void enqueue(int x)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        Queue[rear] = x;
    }
    else if ((rear + 1) % N == front) // for circular queue
    {
        cout << "Queue is Full !";
    }
    else
    {
        rear = (rear + 1) % N; // for circular queue
        Queue[rear] = x;
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is empty !";
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        cout << "The " << Queue[front] << " has been removed " << endl;
        front = (front + 1) % N;
    }
}
void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        cout << "Queue is empty !";
    }
    else
    {
        while (i != rear)
        {
            cout << Queue[i] << " ";
            i = (i + 1) % N;
        }
        cout << Queue[rear];
        cout << endl;
    }
}
int main()
{

    enqueue(4);
    enqueue(7);
    enqueue(8);
    enqueue(20);
    enqueue(8);
    display();
    dequeue();
    dequeue();
    enqueue(7);
    cout << "front : " << front << endl;
    cout << "rear : " << rear << endl;
    display();
    return 0;
}