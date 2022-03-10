#include<stdio.h>
int main()
{
    int i=100;
    {
        int i=0;
        printf("%d", i==0);
    }
    return 0;
}
