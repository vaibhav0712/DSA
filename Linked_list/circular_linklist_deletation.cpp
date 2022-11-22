#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *newnode, *head, *temp, *prv, *tail, *dele_pos;
    int over = 1;
    head = NULL;
    while (over)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        cout << "enter value :";
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
        tail = temp; // tail at last node
        temp->next = head;
        cout << "is there any new node : ";
        cin >> over;
    }
    //* deleting node form begignig // also can be done by tail pointer
    // temp->next = head->next;
    // temp = head;
    // head = head->next;
    // free(temp);

    //* deleting node from end // also can be done by tail pointer
    // temp = head;
    // while (temp->next != head)
    // {
    //     prv = temp;
    //     temp = temp->next;
    // }
    // prv->next = head;
    // free(temp);

    //* deleting node for any pos
    temp = head;
    int pos, i = 1;
    cout << "enter pos to delete node : ";
    cin >> pos;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    dele_pos = temp->next; // pointing to delete node
    temp->next = dele_pos->next;
    free(dele_pos);

    //* printing of all node
    temp = head;
    while (temp->next != head)
    {
        cout << " " << temp->data;
        temp = temp->next;
    }
    cout << " " << temp->data;
    return 0;
}