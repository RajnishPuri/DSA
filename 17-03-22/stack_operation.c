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

st *cretecapacity(int capacity)
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
        printf("Stack is Overflow\n");
        return;
    }
    else
    {
        S->top = S->top + 1;
        scanf("%d", &S->array[S->top]);
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
        printf("Poped Element is : %d\n", S->array[S->top]);
        S->top = S->top - 1;
        return 0;
    }
}

int peek(st *S)
{
    if (isEmpty(S))
    {
        printf("Stack is Empty\n");
        return INT_MIN;
    }
    else
    {
        printf("Stack peek value is : %d\n", S->array[S->top]);
        return 0;
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

void display(st *S, int capacity)
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
            printf("Element %d is : %d\n", S->top+1, S->array[S->top]);
            S->top = S->top - 1;
        }
    }
}

// createcapacity
// isEmpty
// size
// isFull
// push
// pop
// peek
// delete

int main()
{
    int capacity;
    printf("Enter the Size of the stack : ");
    scanf("%d", &capacity);
    st *stk = cretecapacity(capacity);
    for (int i = 0; i < capacity; i++)
    {
        push(stk);
    }
    peek(stk);
    printf("Size of the Stack is : %d\n", size(stk));
    pop(stk);
    display(stk, capacity);
    delete (stk);

    return 0;
}
