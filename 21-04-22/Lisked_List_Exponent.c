#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float power(float a, int b)
{
    int i = 0;
    float value = 1;
    for (i = 0; i < b; i++)
    {
        value = value * a;
    }
    return value;
}


struct node
{
    float Coefficient;
    int exponent;
    struct node *next;
};

struct node *polynomial(struct node *head, float x)
{
    float result = 0.0;
    while (head != NULL)
    {
        result = result + head->Coefficient * (power(x, head->exponent));
        head = head->next;
    }
    printf("After Solving that Polynomial, Answer is : %f\n", result);
}


int main()
{
    struct node *p, *prev, *head;
    int degree;
    printf("Enter the highest degree of the polynomial : ");
    scanf("%d", &degree);

    head = NULL;

    for (int i = 0; i <= degree; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        printf("Enter the Coefficint of the %d exponent : ", degree - i);
        scanf("%f", &p->Coefficient);
        p->exponent = degree - i;

        if (head == NULL)
        {
            head = p;
        }
        else
        {
            prev->next = p;
        }
        prev = p;
        prev->next = NULL;
    }

    float x;

    printf("Enter the value of x to solve that polynomial : ");
    scanf("%f", &x);

    polynomial(head, x);

    return 0;
}
