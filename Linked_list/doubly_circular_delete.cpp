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

    //* delete the node from beginig
    // temp->next = head->next;
    // head->next->prv = temp;
    // temp = head;
    // head = head->next;
    // free(temp);

    //* delete the node from end
    // temp->prv->next = head;
    // head->prv = temp->prv;
    // free(temp);
    // cout << "temp : " << temp->data << endl;

    //* delete from any pos // it will only delete element expect from first and last
    // int pos, i = 1;
    // cout << "enter pos to delete : ";
    // cin >> pos;
    // temp = head;
    // while (i < pos)
    // {
    //     temp = temp->next;
    //     i++;
    // }
    // temp->next->prv = temp->prv;
    // temp->prv->next = temp->next;
    free(temp);
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