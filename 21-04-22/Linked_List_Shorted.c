#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *insert(struct node *head, int value)
{
    struct node *temp;
    struct node *newP = malloc(sizeof(struct node));

    newP->data = value;
    newP->next = NULL;

    int key = value;
    if (head == NULL || key < head->data)
    {
        temp->next = head;
        head = newP;
    }
    else
    {
        temp = head;
        while (temp->next != NULL && temp->next->data < key)
        {
            temp = temp->next;
        }
        newP->next = temp->next;
        temp->next = newP;
    }
    return head;
}

void display(struct node *head)
{
    int i = 1;
    while (head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}

int main()
{
    struct node *p, *prev, *head;
    int num;
    printf("Enter the total number of element in the Linked List : ");
    scanf("%d", &num);

    head == NULL;

    for (int i = 0; i < num; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &p->data);

        if (head==NULL)
        {
            head = p;
        }
        else{
            prev->next=p;
        }
        prev=p;
        prev->next=NULL;        
    }

    for (int i = 0; i < num; i++)
    {
        insert(head, )
    }
    

    display(head);

    return 0;
}
