#include <iostream>
using namespace std;
#include "array.h"
struct Array
{
    // int *p; --> for dynamic allocation
    int A[20];
    int size;
    int length;
};

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void display(struct Array arr) // display element of array
{
    cout << "Element of array : ";
    for (int i = 0; i < arr.length; i++)
        cout << arr.A[i] << " ";
}

void append(struct Array *arr, int x) // changing data through address
{
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;
}

void insert(struct Array *arr, int index, int x) // insert at any index
{
    int i;
    if (index >= 0 && index <= arr->length)
    {
        for (i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index) // delete from any index
{
    int ele = arr->A[index];
    if (index >= 0 && index < arr->length)
    {
        int i;
        for (i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];
        arr->length--;
    }
    return ele;
}

int Search(struct Array *arr, int key) // function return index of found element
{
    int temp = 0;
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == key) // swap with i-1
        {
            // Method - 1
            Swap(&arr->A[i], &arr->A[i - 1]);

            // Method - 2
            // Swap(&arr->A[i], &arr->A[0]);
        }
    }
    return -1;
}

int BinarySearch(struct Array *arr, int key) // function for binary search
{
    int mid, l, h;
    l = 0;
    h = arr->length - 1;
    while (h >= l)
    {
        mid = (l + h) / 2;
        if (key == arr->A[mid])
        {
            return mid;
        }
        else if (key > arr->A[mid])
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return -1;
}

int RBinarySearch(int a[], int key, int l, int h)
{
    if (l <= h)
    {
        int mid = (l + h) / 2;
        if (key == a[mid])
        {
            return mid;
        }
        else if (key > a[mid])
        {
            return RBinarySearch(a, key, mid + 1, h);
        }
        else
        {
            return RBinarySearch(a, key, l, mid - 1);
        }
    }
    return -1;
}

void SortInsert(struct Array *arr, int x) // insert new ele in sorted array
{
    int i = arr->length - 1;
    while (arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}

void merge(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    int i = 0, j = 0, k = 0;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            arr3->length++;
        }
        else
        {
            arr3->A[k++] = arr2->A[j++];
            arr3->length++;
        }
    }
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i++];
        arr3->length++;
    }
    for (; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j++];
        arr3->length++;
    }
    // display the new
    cout << "\nmerge array :";
    for (int k = 0; k < arr3->length; k++)
    {
        cout << arr3->A[k] << " ";
    }
}

int CheckSorted(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            return false;
        }
    }
    return true;
}

void missingele()
{
    int A[] = {15, 12, 9, 5, 7, 4, 2};
    int lenA = sizeof(A) / sizeof(A[0]);
    int h = max_of_array(A, lenA); // max element from array.h
    int l = min_of_array(A, lenA); // min element from array.h
    int H[h];                      // hash table
    for (int i = 0; i < h; i++)
    {
        H[i] = 0;
    }
    // checking is element is present
    for (int i = 0; i < lenA; i++)
    {
        H[A[i]] = 1;
    }
    // to get missing element
    for (int i = l; i <= h; i++) // start from lower element
    {
        if (H[i] == 0)
            cout << "element: " << i << endl;
    }
}

void Duplicates()
{
    int a[] = {2, 3, 5, 5, 7, 9, 10, 10, 11, 14, 15, 15, 15, 17};
    int len = sizeof(a) / sizeof(a[0]);
    int i = 0, lastDuplicate = 0;
    for (i; i < len; i++)
    {
        if (a[i] == a[i + 1] && a[i] != lastDuplicate)
        {
            cout << a[i] << endl;
            lastDuplicate = a[i];
        }
    }
}

void Duplicates_M1() // to find number of duplicate elemtes
{
    int a[] = {2, 3, 5, 5, 7, 9, 10, 10, 11, 14, 15, 15, 15, 17};
    int len = sizeof(a) / sizeof(a[0]);
    int i = 0, j = 0, lastDuplicate = 0;
    ;
    for (i; i < len; i++)
    {
        if (a[i] == a[i + 1] && a[i] != lastDuplicate)
        {
            lastDuplicate = a[i];
            j = i;
            while (a[i] == a[j])
            {
                j++;
            }
            cout << a[i] << " -> " << j - i << " times" << endl;
        }
    }
}

void Duplicates_Unsort()
{
    int a[] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
    int len = sizeof(a) / sizeof(a[0]);
    int i = 0, j = 0, count = 1;
    for (i; i < len - 1; i++)
    {
        j = i + 1;
        count = 1;
        for (j; j < len; j++)
        {
            if (a[i] == a[j] && a[j] != -1)
            {
                a[j] = -1;
                count++;
            }
        }
        if (count > 1)
        {

            cout << a[i] << " -> " << count << " times" << endl;
        }
    }
}
int main()
{
    struct Array arr = {{2, 4, 8, 16, 17}, 20, 5};
    struct Array arr1 = {{1, 3, 5, 7, 9}, 20, 5};
    struct Array arr2 = {{2, 4, 6, 8, 10, 12}, 20, 6};
    int key = 7;
    // struct Array *arr3;

    // For dynamic allocation of an array
    // int n, i;
    // cout << "Enter the size of array : ";
    // cin >> arr.size;
    // arr.p = new int[arr.size];
    // cout << "Enter the number of numbers : ";
    // cin >> n;
    // arr.length = n;
    // cout << "Enter all element's of array\n";
    // for (i = 0; i < n; i++)
    // {
    //     cin >> arr.p[i];
    // }

    // append(&arr, 7); // time complexity O(1)

    // insert(&arr, 4, 10); // time complexity O(n)

    // Delete(&arr, 2); // time complexity O(n)

    // Search(&arr, 7); // time complexity O(n)

    // cout << "\n The element " << key << " found at index : " << BinarySearch(&arr, key);
    // cout << "\n The element " << key << " found at index : " << RBinarySearch(arr.A, key, 0, arr.length);

    // SortInsert(&arr, 12);

    // cout << "\nIs sorted : " << CheckSorted(arr) << endl;
    // display(arr);
    // merge(&arr1, &arr2);
    // missingele();
    // Duplicates();
    // Duplicates_M1();
    Duplicates_Unsort();
    return 0;
}