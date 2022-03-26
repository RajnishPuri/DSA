#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node SN;

struct stack
{
    struct node *top;
};

typedef struct stack ST;

ST *createstack(){
    ST *stk;
    stk=malloc(sizeof(SN));
    stk->top=NULL;
    return stk;
}



void push(int data, ST *s)
{   
    SN *temp;
    temp=malloc(sizeof(SN));
    if (!temp)
    {
        printf("Stack/Heap Overflow\n");
        return;
    }
    temp->data=data;
    temp->next=s->top;
    s->top=temp;
   
}



int pop(ST *s)
{   
    int data;
    SN *temp;
    if (s->top == NULL)
    {
        printf("Enmpty Stack\n");
        return 0;
    }
    temp=s->top;
    s->top = s->top->next;
    data=temp->data;
    free(temp);
    return data;
}

// void display(ST *s, SN *Node)
// {
//     struct node *temp;
//     temp = Node;
//     int i = 1;
//     if (s->top == 0)
//     {
//         printf("Empty Stack\n");
//     }

//     while (Node->next != 0)
//     {
//         printf("Element %d is : %d\n", i, temp->data);
//         i++;
//         temp = temp->next;
//     }
// }

int main()
{
    int i=0;
    ST *stk=createstack();
    int choose;
    int data;
    while(1){
    printf("Press '1' for Push\n");
    printf("Press '2' for Pop\n");
    printf("Press '3' for Display\n");
    printf("Press '4' for Exit\n");

    scanf("%d", &choose);

    

    switch (choose)
    {
    case 1:
        printf("Enter the Number for push : ");
        scanf("%d", &data);
        push(data, stk);
        break;

    case 2:
        printf("Poped Element is : %d\n", pop(stk));
        break;

    case 3:
        // display(stk.top, p);
        break;

    case 4:
        exit(0);
        break;

    default:
        printf("Invalid Input\n");
    }
    }

    return 0;
}
