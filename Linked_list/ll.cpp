#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *link;
    struct Node *prv;
};
Node *head = NULL;

void creatll(int a[], int len)
{
    Node *temp, *newNode;
    for (int i = 0; i < len; i++)
    {
        newNode = new Node;
        newNode->data = a[i];
        newNode->link = NULL;
        newNode->prv = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->link = newNode;
            newNode->prv = temp;
            temp = temp->link;
        }
    }
}

void inseratend()
{
}

void display()
{
    Node *temp;
    temp = head;
    cout << "linked list" << endl;
    while (temp != NULL)
    {
        cout << temp->data << " prv: " << temp->prv << " current :" << temp << " next: " << temp->link << endl;
        temp = temp->link;
    }
}

int main()
{

    int a[] = {1, 2, 3, 4, 5}, len = 5;
    creatll(a, len);
    display();
    return 0;
}