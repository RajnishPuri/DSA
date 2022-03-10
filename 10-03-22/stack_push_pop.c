#include <stdio.h>
#include <stdlib.h>
#define num 10
struct stack
{
    int stk[num];
    int top;
};
typedef struct stack ST;
ST s1;

void push()
{
    if (s1.top == num)
    {
        printf("Stack is Full\n");
        return;
    }
    else
    {
        s1.top = s1.top + 1;
        printf("Enter the Element : ");
        scanf("%d", &s1.stk[s1.top]);
    }
}

void pop()
{
    if (s1.top == -1)
    {
        printf("Stack is Empty\n");
        return;
    }
    else
    {
        int number;
        number = s1.stk[s1.top];
        s1.top = s1.top - 1;
        printf("Poped Element is %d\n", number);
        
    }
}

void display()
{
    if (s1.top == -1)
    {
        printf("Stack is Empty\n");
        return;
    }
    else
    {   
        int i=s1.top;
        while (i!=-1)
        {
            printf("Element %d is : %d\n", i + 1, s1.stk[i]);
            i=i-1;
        }
    }
}
int main()
{
    int ch;
    s1.top = -1;

    while (1)
    {
        printf("Enter the operation -------- \n");
        printf("Enter '1' for Push  \n");
        printf("Enter '2' for Pop  \n");
        printf("Enter '3' for Display  \n");
        printf("Enter '4' for Exit  \n");
        printf("----------------------\n");

        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
        default:
            printf("Invalid Operation\n");
            break;
        }
    }

    return 0;
}
