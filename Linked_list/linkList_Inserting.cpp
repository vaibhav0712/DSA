#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
int main()
{
    int is_over = 1, pos, i = 1;
    struct node *head, *newnode, *temp;
    head = NULL;
    //* creating nodes
    while (is_over)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        cout << "Enter value of element : ";
        cin >> newnode->data;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        cout << "You want to enter new ? 0 or 1 :";
        cin >> is_over;
    }

    //* Insert node to beginning
    // newnode = (struct node *)malloc(sizeof(struct node));
    // cout << "Enter new element to add : ";
    // cin >> newnode->data;
    // newnode->next = head;
    // head = newnode;

    //* Insert node to End
    // newnode = (struct node *)malloc(sizeof(struct node));
    // cout << "Enter new element to add : ";
    // cin >> newnode->data;
    // newnode->next = NULL;
    // temp->next = newnode;

    //* Insert node at any pos
    cout << "Enter pos to new element : ";
    cin >> pos; // Enter pos for new element
    newnode = (struct node *)malloc(sizeof(struct node));
    cout << "Enter data for new node :";
    cin >> newnode->data;
    newnode->next = NULL;
    temp = head;    // set temp to head
    pos--;          // we have to run loop pos-1 so pos--
    while (i < pos) // i = 1 for starting
    {
        temp = temp->next; // moving temp to link new element
        i++;
    }
    // connectin nodes with new node
    newnode->next = temp->next;
    temp->next = newnode;

    //* printing all nodes data
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}