#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct stack
{
    int capacity;
    int top;
    int *array;
};

typedef struct stack ST;

ST *createstack(int capacity)
{
    ST *s = malloc(sizeof(ST));
    if (!s)
    {
        return 0;
    }
    s->capacity = capacity;
    s->top = -1;
    s->array = malloc(capacity * sizeof(ST));
    if (!s->array)
    {
        return 0;
    }
    return s;
}

int isEmpty(ST *s)
{
    if (s->top == -1)
    {
        return INT_MIN;
    }
    return 0;
}

int isFull(ST *s)
{
    return (s->top + 1 == s->capacity);
}

void doublestack(ST *s)                                      // Dynamically allocated Stack
{
    s->capacity *= 2;
    s->array = realloc(s->array, s->capacity * sizeof(ST));
}

void push(ST *s)
{
    if (isFull(s))
    {
        int choice;
        printf("Stack is Full\n");
        printf("Press Anyvalue Except '0' for Double your stack Capacity and Push Operatiion : ");
        scanf("%d", &choice);
        if (choice != 0)
        {
            doublestack(s);                                  // Implementation
            goto raj;
        }
        return;
    }
raj:
    scanf("%d", &s->array[++s->top]);
    printf("Push is Successful\n");
    return;
}

int pop(ST *s)
{
    int data;
    if (isEmpty(s))
    {
        return 0;
    }
    return (s->array[s->top--]);
}

int size(ST *s)
{
    if (isEmpty(s))
    {
        printf("Stack is Empty\n");
        return 0;
    }
    printf("Size of Stack is : %d\n", s->top);
    return 0;
}

void display(ST *s, int capacity)
{
    int index = capacity;
    ST *temp = malloc(sizeof(ST));
    temp->top = s->top;

    if (isEmpty(s))
    {
        printf("Stack is Empty\n");
        return;
    }

    while (temp->top != -1)
    {

        printf("Element %d is : %d\n", temp->top + 1, s->array[temp->top]);
        temp->top = temp->top - 1;
    }
}

void delete (ST *s)
{
    if (s)
    {
        if (s->array)
        {
            free(s->array);
        }
        free(s);
    }
}

int main()
{
    int capacity;
    printf("Enter the total number of element for Stack : ");
    scanf("%d", &capacity);

    ST *stk = createstack(capacity);

    while (1)
    {

        int choose;
        printf("--------------> STACK OPERATION <---------------\n");
        printf("Press '1' for Push Operation\n");
        printf("Press '2' for Pop Operation\n");
        printf("Press '3' for Display Operation\n");
        printf("Press '4' for Delete Operation\n");
        printf("Press '5' for Exit\n");

        scanf("%d", &choose);

        switch (choose)
        {
        case 1:
            push(stk);
            break;
        case 2:
            printf("Poped Element is %d\n", pop(stk));
            break;
        case 3:
            display(stk, capacity);
            break;
        case 4:
            delete (stk);
            break;
        case 5:
            exit(0);
        default:
            printf("INVALID INPUT\n");
            break;
        }
    }

    return 0;
}
