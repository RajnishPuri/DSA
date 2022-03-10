#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct stack
{
    int top;
    int capacity;
    int *array;
};

typedef struct stack ST;
ST s1;

ST *createstack(int capacity)
{
    ST *s = malloc(sizeof(ST));
    if (!s)
    {
        return NULL;
    }
    s->capacity = capacity;
    s->top = -1;
    s->array = malloc(s->capacity * sizeof(int));
    if (!s->array)
    {
        return NULL;
    }
    return s;
}

int isEmpty(ST *s)
{
    return (s->top == -1); // if the condition is true it returns 1 and if it is false then its returns 0
}

int size(ST *s)
{
    return (s->top + 1);
}

int isFull(ST *s)
{   
    //if condition is true return 1 else return 0
    return (s->top == s->capacity - 1);
}

void doublestack(ST *s)
{
    s->capacity *= 2;
    s->array = realloc(s->array, s->capacity * sizeof(int));
}

void push(ST *s, int data)
{
    if (isFull(s))
        doublestack(s);  // dynamic stack
    s->array[++s->top] = data;
}

int pop(ST *s)
{
    if (isEmpty(s))
    {   
        //s->top == -1 indicates empty stack
        printf("Stack is Empty\n");
        return INT_MIN;
    }
    else
    {   
        //removing element from top of the array and reducing top by 1
        return (s->array[s->top--]);
    }
}

int peek(ST *s)
{   
    //s->top == -1 indicates empty stack
    if (isEmpty(s))
    {
        printf("Stack is Empty\n");
        return INT_MIN;
    }
    else
    {
        return (s->array[s->top]);
    }
}

void deletestack(ST *s)
{
    if (s)
    {
        if (s->array)
        {
            free(s->array);
            free(s);
        }
    }
}

int main()
{
    int i = 0, capacity = 5;
    ST *stk = createstack(capacity);
    for (int i = 0; i <= 2 * capacity; i++)
    {
        push(stk, i);
    }
    printf("Top element is : %d\n", peek(stk));
    printf("Stack size is : %d\n", size(stk));

    for (int i = 0; i <= capacity; i++)
    {
        printf("Popped Element is : %d\n", pop(stk));
    }

    if (isEmpty(stk))
    {
        printf("Stack is Empty\n");
    }

    else
    {
        printf("Stack is Not Empty\n");
    }

    deletestack(stk);

    return 0;
}
