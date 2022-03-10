#include<stdio.h>
int main()
{
    int y=200;
    const int x=y;
    x=10;
    printf("%d\n", x);
    return 0;
}
