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
    int over = 1, pos, i = 1;
    head = NULL;
    while (over)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        cout << "enter data :";
        cin >> newnode->data;
        newnode->prv = newnode->next = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            newnode->prv = temp;
            temp->next = newnode;
            temp = temp->next;
        }
        cout << "want to add new node : ";
        cin >> over;
    }
    //* delete from begining
    // temp = head;
    // head = head->next;
    // head->prv = NULL;
    // free(temp);

    //* delete from last
    // temp is pointing to last element
    // temp->prv->next = NULL;
    // temp->prv = NULL;
    // free(temp);

    //* delet from any pos
    // temp = head;
    // cout << "enter pos to delete element ";
    // cin >> pos;
    // while (i < pos) // movint temp to pos
    // {
    //     temp = temp->next;
    //     i++;
    // }
    // temp->prv->next = temp->next;
    // temp->next->prv = temp->prv;
    // free(temp);

    temp = head;
    while (temp != NULL) // printing data with address
    {
        cout << temp->data << " prev: " << temp->prv << " curr : " << temp << " next : " << temp->next << endl;
        temp = temp->next;
    }
    return 0;
}