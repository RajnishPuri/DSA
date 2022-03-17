#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct stack
{
    int capacity;
    int top;
    int *array;
};

typedef struct stack st;

st *createstack(int capacity)
{
    st *S = malloc(sizeof(st));
    if (!S)
    {
        return NULL;
    }
    S->capacity = capacity;
    S->top = -1;
    S->array = malloc(S->capacity * sizeof(int));
    if (!S->array)
    {
        return NULL;
    }
    return S;
}

int isEmpty(st *S)
{
    return (S->top == -1);
}

int size(st *S)
{
    return (S->top + 1);
}

int isFull(st *S)
{
    return (S->top + 1 == S->capacity);
}

void push(st *S)
{
    if (isFull(S))
    {
        doublestack(S);                                      // Dynamic
    }
    else
    {
        scanf("%d", &S->array[++S->top]);
    }
}

int pop(st *S)
{
    if (isEmpty(S))
    {
        printf("Stack is Empty\n");
        return INT_MIN;
    }
    else
    {
        return (S->array[S->top--]);
    }
}

int peek(st *S)
{
    if (isEmpty(S))
    {
        printf("Satck is Empty\n");
        return INT_MIN;
    }
    else
    {
        return (S->array[S->top]);
    }
}
void display(st *S)
{
    if (isEmpty(S))
    {
        printf("Stack is Empty\n");
        return;
    }
    else
    {
        while (S->top != -1)
        {
            printf("Element %d is : %d\n", S->top + 1, S->array[S->top]);
            S->top = S->top - 1;
        }
    }
}

void delete (st *S)
{
    if (S)
    {
        if (S->array)
        {
            free(S->array);
        }
        free(S);
    }
}

void doublestack(st *S)                                       // Dynamic
{
    S->capacity *= 2;
    S->array = realloc(S->array, S->capacity * (sizeof(int)));
}

int main()
{
    int capacity;
    printf("Enter the size of the stack : ");
    scanf("%d", &capacity);
    st *S = createstack(capacity);
    for (int i = 0; i <= 2 * capacity; i++)
    {
        push(S);
    }
    printf("Poped element is : %d\n", pop(S));
    printf("Peek Value of Stack is : %d\n", peek(S));
    display(S);
    delete (S);
    display(S);

    return 0;
}
