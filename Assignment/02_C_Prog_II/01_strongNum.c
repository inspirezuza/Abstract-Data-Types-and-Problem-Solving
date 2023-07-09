#include <stdio.h>

int fac(int n)
{
    if (n == 0)
        return 1;
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

int isStrongNumber(int n)
{
    int step = 1;
    int check = 0;
    while (step <= n)
    {
        check += fac((n % (step * 10)) / step);
        step *= 10;
    }
    if (n == check)
        return 1;
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int m;
        scanf("%d", &m);
        for (int j = m - 1; j >= 1; j--)
        {
            if (isStrongNumber(j))
            {
                printf("%d\n", j);
                break;
            }
        }
    }
    return 0;
}