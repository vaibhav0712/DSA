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

    //* inserting at begining // it can also done by tail pointer
    // newnode = (struct node *)malloc(sizeof(struct node));
    // cout << "enter the value of newnode : ";
    // cin >> newnode->data;
    // temp->next = newnode;
    // newnode->next = head;
    // head = newnode;

    //* inserting at end // it can also done by tail pointer
    // newnode = (struct node *)malloc(sizeof(struct node));
    // cout << "enter the value of new node : ";
    // cin >> newnode->data;
    // temp->next = newnode;
    // newnode->next = head;

    //* inserting at any pos
    int pos, i = 1;
    newnode = (struct node *)malloc(sizeof(struct node));
    cout << "enter the value of new node : ";
    cin >> newnode->data;
    cout << "enter pos to enter new node : ";
    cin >> pos;
    temp = head;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;

    temp = head;
    while (temp->next != head)
    {
        cout << " " << temp->data << "add :" << temp << " next :" << temp->next << endl;
        temp = temp->next;
    }
    cout << " " << temp->data << "add :" << temp << " next :" << temp->next << endl; // printing last elemet of list
    return 0;
}