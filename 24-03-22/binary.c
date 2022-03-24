#include <stdio.h>
#include <math.h>
int main()
{
    int num;
    scanf("%d", &num);

    int binary = 0, i = 0, remainder;

    while (num != 0)
    {
        remainder = ((num % 2) * pow(10, i));
        binary = binary + remainder;
        num = num / 2;
        i++;
    }

    printf("%d\n", binary);

    return 0;
}
