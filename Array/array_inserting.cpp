//*******************
/// array inserting //
//*******************

#include <iostream>
using namespace std;
int main()
{
    int arr[5] = {8, 5, 4, 1};
    int len = sizeof(arr) / sizeof(arr[0]); // length of array N = 5
    int pos, new_x;
    cout << "Before insert : ";
    for (int i = 0; i < len - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Enter pos to enter element : ";
    cin >> pos; // pos of new element "index = pos - 1"
    cout << "Enter value of element : ";
    cin >> new_x;                            // value of new element
    for (int i = len - 1; i >= pos - 1; i--) // start from last_index = len - 1 ---> stop new_index = pos - 1
    {
        if (i == pos - 1) // if i == new_index insert new element
        {
            arr[i] = new_x;
        }
        else
        {
            arr[i] = arr[i - 1]; // else shift the elements to backward
        }
    }
    cout << "After insert : ";
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}