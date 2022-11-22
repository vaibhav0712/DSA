#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *head, *newnode, *temp;
    int over = 1;
    head = NULL;
    while (over)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        cout << "enter data :";
        cin >> newnode->data;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = temp->next;
        }
        temp->next = head;
        cout << "is ther any new node ? :";
        cin >> over;
    }
    temp = head;
    while (temp->next != head)
    {
        cout << " " << temp->data << "add :" << temp << " next :" << temp->next << endl;
        temp = temp->next;
    }
    cout << " " << temp->data << "add :" << temp << " next :" << temp->next << endl; // printing last elemet of list
    return 0;
}