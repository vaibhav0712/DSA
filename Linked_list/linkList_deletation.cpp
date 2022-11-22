#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
int main()
{
    int pos;
    int is_over = 1;
    struct node *head, *temp, *newnode, *temp2;
    head = NULL;
    while (is_over)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        cout << "Enter data :";
        newnode->next = NULL;
        cin >> newnode->data;

        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        cout << "Enter you want to enter 0 or 1 : ";
        cin >> is_over;
    }
    // deletation from starting
    // temp = head;
    // head = head->next;
    // free(temp);

    // deletation from End
    // temp = temp2 = head;
    // while (temp->next != NULL)
    // {
    //     temp2 = temp;
    //     temp = temp->next;
    // }
    // temp2->next = NULL;
    // free(temp);
    // temp = NULL;

    // deletation at any pos
    temp = temp2 = head;
    cout << "Enter pos to delet elemet :";
    cin >> pos;
    int i = 1;
    while (i < pos)
    {
        temp2 = temp;
        temp = temp->next;
        i++;
    }
    temp2->next = temp->next;
    temp->next = NULL;
    delete (temp);

    temp = head;
    while (temp != NULL)
    {
        cout << " " << temp->data;
        temp = temp->next;
    }
    return 0;
}