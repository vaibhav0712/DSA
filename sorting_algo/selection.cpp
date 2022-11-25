#include <iostream>
using namespace std;
void sort(int arr[], int len)
{
    int temp;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[i])
            {

                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void display(int arr[], int len)
{
    cout << "element of array : ";
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {10, 4, 6, 2, 3, 1, 100, 99, 56, 23, 11, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    display(arr, len);
    sort(arr, len);
    display(arr, len);
    return 0;
}