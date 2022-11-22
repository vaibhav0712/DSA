#include <iostream>
using namespace std;
void twosum()
{
    int arr[] = {3, 2, 4, 12, 8, 10, 5};
    int target = 8;
    int ans = 0;
    int i = 0;
    int len = sizeof(arr) / sizeof(arr[0]);
    int j = len - 1;
    while (ans != target)
    {
        if (j > i)
        {
            ans = arr[j] + arr[i];
            j--;
        }
        else
        {
            i++;
            j = len - 1;
        }
    }
    cout << ans << endl;
    cout << i << j + 1;
}

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void moveZero()
{
    int a[] = {0, 1};
    int i = 0, j = 0;
    int len = sizeof(a) / sizeof(a[0]);
    for (i; i < len - 1; i++)
    {
        if (a[i] == 0)
        {
            j = i;
            while (a[j] == 0 && j < len - 1)
            {
                j++;
            }
            Swap(&a[i], &a[j]);
        }
    }
    for (int k = 0; k < len; k++)
    {
        cout << a[k] << endl;
    }
}

struct rectangel
{
    int a[10];
    int length;
    int breath;
};
void Basic()
{
    int a[] = {1, 2, 3, 4, 5};
    for (int x : a) // for each loop
    {
        cout << x << endl;
    }
}
int main()
{
    Basic();
    return 0;
}