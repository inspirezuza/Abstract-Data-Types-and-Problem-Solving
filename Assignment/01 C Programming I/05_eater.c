#include <math.h>
#include <stdio.h>

int main(void)
{
    float x, y, z;
    scanf("%f %f %f", &x, &y, &z);

    char a, b;
    scanf(" %c %c", &a, &b); // Add a space before %c (%c will read newline char)

    if ((a == 'N') || (a == 'n'))
    {
        y = 0.0;
    }
    if ((b == 'N') || (b == 'n'))
    {
        z = 1.0;
    }
    printf("%d", (int)((x + y + z - 1) / z)); // wanna use ceil() but it's raise an error so i use this Approach
    return 0;
}