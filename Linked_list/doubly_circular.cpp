#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
    struct node *prv;
};
int main()
{
    struct node *head, *temp, *newnode;
    int over = 1;
    head = NULL;
    while (over)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        cout << "enter data : ";
        cin >> newnode->data;
        newnode->next = NULL;
        newnode->prv = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prv = temp;
            temp = temp->next;
        }
        temp->next = head;
        head->prv = temp;
        cout << "is ther any new node ? : ";
        cin >> over;
    }
    temp = head;
    while (temp->next != head)
    {
        cout << temp->data << " "
             << " prv : " << temp->prv << " "
             << " curr : " << temp << " "
             << " next : " << temp->next << endl;
        temp = temp->next;
    }
    cout << temp->data << " "
         << " prv : " << temp->prv << " "
         << " curr : " << temp << " "
         << " next : " << temp->next << endl;
    return 0;
}