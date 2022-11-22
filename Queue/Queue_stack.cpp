// creating Queue using stack
#include <iostream>
using namespace std;
#define N 5
int top1 = -1, top2 = -1;
int count = 0;
int stack1[N], stack2[N];
void push1(int x);
void push2(int x);
int pop1();
int pop2();
void enqueue(int x)
{
    push1(x);
    count++;
}
void push1(int x)
{
    if (top1 == N - 1)
    {
        cout << "Queue is full" << endl;
    }
    else
    {
        top1++;
        stack1[top1] = x;
    }
}
void dequeue()
{
    if (top1 == -1 && top2 == -1)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    else
    {
        cout << "The " << stack1[top1] << " has been removed " << endl;
        for (int i = 0; i < count; i++)
        {
            int a = pop1();
            push2(a);
        }
        count--;
        for (int i = 0; i < count; i++)
        {
            int a = pop2();
            push1(a);
        }
    }
}
int pop1()
{
    int x;
    x = stack1[top1];
    top1--;
    return x;
}
int pop2()
{
    int x;
    x = stack2[top2];
    top2--;
    return x;
}
void push2(int x)
{
    if (top1 == N - 1)
    {
        cout << "Queue is full" << endl;
    }
    else
    {
        top2++;
        stack2[top2] = x;
    }
}
void display()
{
    if (top1 == -1 && top2 == -1)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue:";
    for (int i = 0; i <= top1; i++)
    {
        cout << stack1[i] << " ";
    }
    cout << endl;
}
int main()
{

    enqueue(4);
    enqueue(6);
    enqueue(8);
    display();
    dequeue();
    display();

    return 0;
}
/*
 OUTPUT:
 Queue:4 6 8
 The 8 has been removed
 Queue:4 6
*/