#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;};
struct node *newnode, *head=NULL,*temp,*top=NULL;
struct node *insert(struct node *tem){
   struct node *newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data");
    scanf("%d",&newnode->data);
    if(tem==0)
    {
        tem=newnode;
        newnode->next=0;
        newnode->prev=0;
    }
    else
    {
        tem->prev=newnode;
        newnode->next=tem;
        tem=newnode;
        tem->prev=NULL;
    }
return tem;
}

void display(struct node *tem)
{
    struct node *i,*j;
    int e;
    for(i=tem;i!=0;i=i->next){
        for(j=i->next;j!=0;j=j->next){
            if(i->data>j->data){
                e=i->data;
                i->data=j->data;
                j->data=e;}}}
    temp=tem;
    printf("\n The Sorted list :\n");
    while(temp!=0){
        printf("\t%d",temp->data);
        temp=temp->next;
        }
}


void merge()
{
    temp=head;
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    temp->next=top;
    top->prev=temp;
}


int main(){
    int choice;
    do{
        printf("\n1.insert 1st list \n2.insert 2nd list \n3.displaysorted1st \n4.displaysorted2nd \n5.merge \n6.sortedmerge");
        printf("\nEnter your choice");
        scanf("%d",&choice);
        switch(choice){
        case 1:
          head=insert(head);
            break;
        case 2:
            top=insert(top);
            break;
        case 3:
            display(head);
            break;
        case 4:
            display(top);
            break;
        case 5:
            merge();
            break;
        case 6:
            display(head);
            break;
        case 7:
            exit(0);
        default:
            printf("\n Invalid position");
            break;}}while(choice!=7);
return 0;}
