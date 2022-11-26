#include <iostream>
#include <time.h>
using namespace std;
// void sort(int arr[], int len)
// {
//     int temp, i_count = 0, j_count = 0;
//     ;
//     for (int i = 0; i < len - 1; i++)
//     {
//         i_count++;
//         for (int j = 0; j < len - 1; j++)
//         {
//             j_count++;
//             if (arr[j] > arr[j + 1])
//             {
//                 temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//         len--;
//     }
//     cout << "i runs : " << i_count << " and j runs : " << j_count << endl;
// }
void bubbleSort(int arr[], int len)
{
    int i, j, i_count = 0, j_count = 0, temp;
    for (i = 0; i < len - 1; i++)
    {
        i_count++;
        for (j = 0; j < len - i - 1; j++)
        {
            j_count++;
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "i runs : " << i_count << " and j runs : " << j_count << endl;
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
    int arr[10];
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 1000;
    }
    int len = sizeof(arr) / sizeof(arr[0]);
    display(arr, len);
    bubbleSort(arr, len);
    display(arr, len);
    return 0;
}