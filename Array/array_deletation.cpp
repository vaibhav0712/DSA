#include <iostream>
using namespace std;
int main()
{
    int arr[8] = {1, 7, 3, 4, 6, 12, 10, 2};
    int len = sizeof(arr) / sizeof(arr[0]); // length of array
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // position of element to delete
    int pos;
    cout << "Enter pos to delete element : ";
    cin >> pos;
    // check index is valid or not
    if (pos > 8 || pos < 0)
    {
        cout << "Invalid index !";
    }
    else
    {
        // form pos - 1 = indexofdelete el to len - 1 = second_last index
        for (int j = pos - 1; j < len - 1; j++)
        {
            arr[j] = arr[j + 1]; // replacing element
        }
        for (int i = 0; i < len - 1; i++)
        {
            cout << arr[i] << " ";
        }
    }
    return 0;
}