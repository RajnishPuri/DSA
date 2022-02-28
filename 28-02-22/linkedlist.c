#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *insertionatbeginning(struct node *head, int key){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=key;
    temp->next=NULL;
    if (head==NULL)
    {
        head=temp;
    }
    else{
        temp->next=head;
        head=temp;
    }
    return head;
}

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
    struct node *prev, *head, *p, *last;
    int num, key, i;
    

    printf("Enter the total number of element : ");
    scanf("%d", &num);
    head=NULL;
    for ( i = 0; i <num; i++)
    {
        p=(struct node *)malloc(sizeof(struct node));
        printf("Enter the %d element : ", i+1);
        scanf("%d", &p->data);
        if (head==NULL)
        {
            head=p;
            last=head;
        }
        else{
            prev->next=p;
        }
        prev=p;
    }
    printf("Enter the element for insertion : ");
    scanf("%d", &key);
    display(insertionatbeginning(last, key));
    return 0;
}
