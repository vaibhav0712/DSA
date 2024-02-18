#include <stdio.h>

void insertionSort(int arr[], int len)
{
    int i, j, key;
    for (i = 1; i < len; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void display(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {10, 4, 6, 2, 2, 3, 1, 100, 99, 56, 10, 23, 11, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    // display(arr, len);
    insertionSort(arr, len);
    display(arr, len);
    return 0;
}