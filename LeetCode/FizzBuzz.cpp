#include <iostream>
#include <string.h>
using namespace std;
string *FB(int n)
{
    string *arr = new string[n];
    for (int i = 1; i <= n; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            arr[i - 1] = "FizzBuzz";
        }
        else if (i % 3 == 0)
        {
            arr[i - 1] = "Fizz";
        }
        else if (i % 5 == 0)
        {
            arr[i - 1] = "Buzz";
        }
        else
        {
            arr[i - 1] = to_string(i);
        }
    }
    return arr;
}
int main()
{
    string *t;
    t = FB(1000);
    for (int i = 0; i < 1000; i++)
    {
        cout << t[i] << " ";
    }
    return 0;
}