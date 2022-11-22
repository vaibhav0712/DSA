#include <iostream>
using namespace std;
struct node
{
    struct node *next;
    int data;
};
struct node *first = 0;
struct node *second = 0;
void creatA(int arr[], int n)
{
    struct node *last, *temp;
    first = new node;
    first->data = arr[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        temp = new node;
        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}
void creatB(int arr[], int n)
{
    struct node *last, *temp;
    second = new node;
    second->data = arr[0];
    second->next = NULL;
    last = second;
    for (int i = 1; i < n; i++)
    {
        temp = new node;
        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

struct node *merge(struct node *s1, struct node *s2)
{
    struct node *dummy, *t;
    dummy = new node;
    t = dummy;
    while (s1 != NULL && s2 != NULL)
    {
        if (s1->data < s2->data)
        {

            t->next = s1;
            s1 = s1->next;
            t = t->next;
        }
        else
        {
            t->next = s2;
            s2 = s2->next;
            t = t->next;
        }
    }

    cout << "merge exit at: " << t->data << endl;
    while (s1 != NULL)
    {

        t->next = s1;
        s1 = s1->next;
        t = t->next;
    }
    while (s2 != NULL)
    {

        t->next = s2;
        s2 = s2->next;
        t = t->next;
    }
    return dummy->next;
}
void display(struct node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int main()
{
    int arrA[] = {7, 9, 19, 49};
    int arrB[] = {8, 10, 14, 18, 20, 25, 50};
    creatA(arrA, sizeof(arrA) / sizeof(arrA[0]));
    creatB(arrB, sizeof(arrB) / sizeof(arrB[0]));
    display(first);
    display(second);
    struct node *p;
    p = merge(first, second);
    display(p);
    return 0;
}