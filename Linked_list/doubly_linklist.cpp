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
    temp = head;
    while (temp != NULL) // printing data with address
    {
        cout << temp->data << " prev: " << temp->prev << " curr : " << temp << " next : " << temp->next << endl;
        temp = temp->next;
    }
    return 0;
}