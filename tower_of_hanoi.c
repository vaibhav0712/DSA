#include <stdio.h>
// n - number of disk
// a - b - c
// 1. move n-1 disk from a to b using c
// 2. print moved last disk from a to c
// 3. move n-1 disk from b to c using a
void toh(int n, char a, char b, char c)
{
    if (n > 0)
    {

        toh(n - 1, a, c, b);
        printf("disk %d move from %c to %c \n", n, a, c);
        toh(n - 1, b, a, c);
    }
}
int main()
{
    toh(3, 'A', 'B', 'C');
    return 0;
}
