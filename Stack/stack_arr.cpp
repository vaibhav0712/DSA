// creating stack data structure
#include <iostream>
using namespace std;
#define Max 4
int stack[Max];
int top = -1;
void push(int data)
{
    if (top == Max - 1)
    {
        cout << "Stack overflow" << endl;
    }
    else
    {
        top++;
        stack[top] = data;
    }
}
int pop()
{
    int data;
    if (top == -1)
    {
        cout << "stock underflow";
        exit(1);
    }
    data = stack[top];
    top--;
    return data;
}
void print()
{
    for (int i = 0; i <= top; i++)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}
void peek()
{
    if (top == -1)
    {
        cout << "stack underflow";
    }
    else
    {
        cout << "top :" << stack[top] << endl;
    }
}
int main()
{
    int deleted_num;
    push(1);
    push(2);
    push(3);
    push(4);
    print();
    peek();
    deleted_num = pop();
    print();
    peek();
    cout << "deleted : " << deleted_num;
    return 0;
}