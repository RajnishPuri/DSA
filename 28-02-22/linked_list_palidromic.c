#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *palidrome(struct node *head){
    
}

void display(struct node *head)
{
    int i = 1;
    while (head != NULL)
    {   
        printf("%d", head->data);
        head = head->next;
        i++;
    }
}

int main()
{
    struct node *p, *prev, *head;
    int num;
    printf("Enter the total number of element in the linked list : ");
    scanf("%d", &num);
    head = NULL;
    for (int i = 0; i < num; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        printf("Enter the %d element : ", i + 1);
        scanf("%d", &p->data);
        if (head == NULL)
        {
            head = p;
        }
        else
        {
            prev->next = p;
        }
        prev = p;
    }
    prev->next = NULL;
    display(head);

    return 0;
}
