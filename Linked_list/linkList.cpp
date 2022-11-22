
#include <iostream>
using namespace std;

// declaration of linklist
struct node
{
    int data;
    struct node *next;
};
int main()
{
    int choice = 1;
    // declaration of head pointer , newnode pointer and temp ponter
    struct node *head, *newnode, *temp;
    // default head pointer to NULL
    head = NULL;
    // run loop to creat new node and link them
    while (choice)
    {
        // new node_created and newnode pointer is pointing to it
        // newnode = (struct node *)malloc(sizeof(struct node)); // using dynamic allocation
        newnode = new node;
        cout << "Enter data : ";
        cin >> newnode->data; // set data into new node
        newnode->next = NULL; // set address of next node is == NULL
        if (head == NULL)     // if head NULL
        {
            head = temp = newnode; // first node is point by head,newnode pointer  and temp
        }
        else
        {
            temp->next = newnode; // storing address of new node into old node
            temp = newnode;       // now temp is pointing to new node
        }
        cout << "Enter 0 or 1 :";
        cin >> choice;
    }
    temp = head; // end of proccess temp is now pointing to head
    cout << "link list : ";
    while (temp != NULL) // display list
    {
        cout << temp->data << " "; // using temp get data
        temp = temp->next;         // updating temp to next node
    }
    return 0;
}
