#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void display(struct node *head){
    int i=1;
    while (head!=NULL)
    {
        printf("Element %d is : %d\n", i, head->data);
        head=head->next;
        i++;
    }
    
}
int main()
{
    struct node *prev, *p, *head;
    int count;
    printf("Enter the total number of element : ");
    scanf("%d", &count);

    head=NULL;
    for (int i = 0; i < count; i++)
    {
        p=(struct node*)malloc(sizeof(struct node));

        printf("Enter the %d Element : ", i+1);
        scanf("%d", &p->data);
        if (head==NULL)
        {
            head=p;
        }
        else{
            prev->next=p;
        }
        prev=p;
        prev->next=NULL;
    }

    display(head);
    
    return 0;
}
