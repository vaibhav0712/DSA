#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
    struct node *prv;
};
struct node *first = NULL;

void creat_linklist(int arr[], int len)
{
    struct node *temp, *newnode;
    for (int i = 0; i < len; i++)
    {

        newnode = new node;
        newnode->next = NULL;
        newnode->prv = NULL;
        newnode->data = arr[i];
        if (first == NULL)
        {
            first = newnode;
            temp = first;
        }
        else
        {
            temp->next = newnode;
            newnode->prv = temp;
            temp = temp->next;
        }
    }
}

void display()
{
    struct node *temp;
    temp = first;
    while (temp != NULL)
    {
        cout << temp->data << " prev: " << temp->prv << " curr : " << temp << " next : " << temp->next << endl;
        temp = temp->next;
    }
}

void revers_linklist()
{
    struct node *temp = NULL;
    struct node *current = first;
    while (current != NULL)
    {
        temp = current->prv;
        current->prv = current->next;
        current->next = temp;
        current = current->prv;
    }
    if (temp != NULL)
    {
        first = temp->prv;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    creat_linklist(arr, len);
    display();
    revers_linklist();
    cout << "After : " << endl;
    display();
    return 0;
}