#include <stdio.h>

int n;
int a[] = {1,2,3,4,1,1};

int equa(int* b, int k, int m, int min, int max)
{
    int x;
    if (m > n)return -1;
    if (min >= max)
    {
        if (min == max)
        {
            return k;
        }
        else return -1;
    }
    b[k] = m;
    if ((x = equa(b, k + 1, m + 1, min + a[m], max - a[m])) > 0)return x;
    if ((x = equa(b, k, m + 1, min, max)) > 0)return x;
    return -1;
}
int main()
{
    int b[29];
    int i, j, max = 0;
    n = sizeof(a) / sizeof(a[0]);
    for (i = 1; i < n; i++)
    {
        max += a[i];
    }
    b[0] = 0;
    if (equa(b, 1, 1, a[0], max) > 0)
        printf("Yes\n");
    else
        printf("NO\n");
    return 0;
}
