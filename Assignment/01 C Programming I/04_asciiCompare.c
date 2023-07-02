#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a, b;
    scanf("%c %c", &a, &b);

    printf("%d", abs(a - b));
    return 0;
}