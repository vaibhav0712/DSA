#include <stdio.h>
void bubblesort(int arr[])
{
    int len = 20, temp;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i; j < len - 1; j++)
        {
        }
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
    int arr[20] = {9, 5, 1, 2, 10, 11, 1, 3, 2, 2, 2, 2, 1, 1, 1, 1, 1, 4, 4, 10};
    display(arr, 20);
    bubblesort(arr);
    display(arr, 20);
    return 0;
}