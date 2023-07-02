#include <stdio.h>

int main()
{
    long t;
    scanf("%ld", &t);

    printf("%ld %ld %ld %ld", t / (60 * 60 * 24),
           (t - ((t / (60 * 60 * 24)) * (60 * 60 * 24))) / (60 * 60),
           t / 60 % 60,
           t % 60);
    return 0;
}
