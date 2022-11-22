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
    //* inserting new node at begining
    // newnode = (struct node *)malloc(sizeof(struct node));
    // cout << "enter new node data : ";
    // cin >> newnode->data;
    // newnode->prv = temp;
    // newnode->next = head;
    // head->prv = newnode;
    // temp->next = newnode;
    // head = newnode;

    //* inseting new node at end
    // newnode = (struct node *)malloc(sizeof(struct node));
    // cout << "enter new node data : ";
    // cin >> newnode->data;
    // newnode->next = head;
    // newnode->prv = temp;
    // temp->next = newnode;
    // head->prv = newnode;

    //* inserting at any pos
    int pos, i = 1;
    newnode = (struct node *)malloc(sizeof(struct node));
    cout << "enter pos for new node : ";
    cin >> pos;
    cout << "enter data for new node : ";
    cin >> newnode->data;
    temp = head;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    newnode->prv = temp;
    temp->next->prv = newnode;
    temp->next = newnode;
    //* printing link list
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