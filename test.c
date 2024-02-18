#include <stdio.h>
int main()
{
    int arr = [ 7, 5, 8, 100, 1 ];
    int len = 5;
    // bubble sort
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap();
            }
        }
    }
    return 0;
}