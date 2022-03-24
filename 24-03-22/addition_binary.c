#include <stdio.h>

int squarepower();

int main()
{
    int num, sum, add, remainder = 0;
    printf("Enter the total number of element for binary addition : ");
    scanf("%d", &num);

    int decimal_array[num];

    for (int i = 0; i < num; i++)
    {
        printf("Enter %d Element : ", i + 1);
        scanf("%d", &decimal_array[i]);
    }

    int binary_array[num];
    int copydecimal_array[num];

    for (int i = 0; i < num; i++)
    {
        copydecimal_array[i] = decimal_array[i];
        int binary = 0, k = 0, remainder=0;

        while (decimal_array[i] != 0)
        {
            remainder = ((decimal_array[i] % 2) * squarepower(k));
            binary = binary + remainder;
            decimal_array[i] = decimal_array[i] / 2;
            k++;
        }

        binary_array[i] = binary;
    }
    remainder=0;

    int j = 0;
    while (binary_array[0] != 0 || binary_array[1] != 0)
    {

        sum = sum + (binary_array[0] % 10 + binary_array[1] % 10 + remainder) % 2 * squarepower(j);
        remainder = (binary_array[0] % 10 + binary_array[1] % 10 + remainder) / 2;
        binary_array[0] = binary_array[0] / 10;
        binary_array[1] = binary_array[1] / 10;
        j++;
    }
    if (remainder != 0){
        sum = sum + remainder * squarepower(j);
    }

    int i = 2;

    if (num > 2)
    {
        while(i<num){
            remainder=0;
        int j = 0;
        while (sum != 0 || binary_array[i] != 0)
        {

            add = add + (sum % 10 + binary_array[i] % 10 + remainder) % 2 * squarepower(j);
            remainder = (sum % 10 + binary_array[i] % 10 + remainder) / 2;
            sum = sum / 10;
            binary_array[i] = binary_array[i] / 10;
            j++;
        }
        if (remainder != 0){
            add = add + remainder * squarepower(j);
        }
        i++;
        sum=add;
    }
    }

    printf("%d\n", add);
    // for (int i = 0; i < num; i++)
    // {
    //     printf("%d => %d\n", copydecimal_array[i], binary_array[i]);
    // }

    return 0;
}
int squarepower(int i)
{
    int t = 0, ans = 1;
    if (i == 0)
    {
        return 1;
    }
    while (t < i)
    {
        ans *= 10;
        t++;
    }
    return ans;
}