#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
int main()
{
    struct node *head, *temp, *newnode;
    int pos, i = 1;
    head = NULL;
    int over = 1;
    while (over)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        cout << "Enter data :";
        cin >> newnode->data;
        newnode->next = NULL;
        newnode->prev = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = temp->next;
        }
        cout << "do you want to add new node ? :";
        cin >> over;
    }
    //* inserting new node in begining
    // newnode = (struct node *)malloc(sizeof(struct node));
    // newnode->prev = newnode->next = NULL;
    // cout << "enter the value of newnode :";
    // cin >> newnode->data;
    // head->prev = newnode;
    // newnode->next = head;
    // head = newnode;

    //* inserting new node at last
    // newnode = (struct node *)malloc(sizeof(struct node));
    // newnode->prev = newnode->next = NULL;
    // cout << "enter the value of newnode :";
    // cin >> newnode->data;
    // temp->next = newnode;
    // newnode->prev = temp;

    //* inserting new node at any pos
    // newnode = (struct node *)malloc(sizeof(struct node));
    // newnode->prev = newnode->next = NULL;
    // cout << "enter the value of newnode :";
    // cin >> newnode->data;
    // cout << "enter the pos of newnode :";
    // cin >> pos;
    // temp = head;
    // while (i < pos - 1)
    // {
    //     temp = temp->next;
    //     i++;
    // }
    // newnode->prev = temp;
    // newnode->next = temp->next;
    // temp->next = newnode;
    // newnode->next->prev = newnode;

    //* printing all nodes
    temp = head;
    while (temp != NULL) // printing data with address
    {
        cout << temp->data << " prev: " << temp->prev << " curr : " << temp << " next : " << temp->next << endl;
        temp = temp->next;
    }
    return 0;
}