int min_of_array(int a[], int len)
{
    int min = a[0];
    for (int i = 0; i < len; i++)
        if (a[i] < min)
            min = a[i];
    return min;
}

int max_of_array(int a[], int len)
{
    int max = a[0];
    for (int i = 0; i < len; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}
