#include <stdio.h>
#include <string.h>
int main()
{
    char str1[100], str2[50];
    printf("Enter the first String\n");
    gets(str1);
    printf("Enter the second string\n");
    gets(str2);

    int size1;
    size1 = strlen(str1);
    str1[size1] = ' ';

    for (int i = size1 + 1, j = 0; i < 100 && j < 50; i++, j++)
    {
        str1[i] = str2[j];
    }
    puts(str1);

    return 0;
}
