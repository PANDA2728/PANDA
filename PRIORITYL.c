#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
int pri;
struct node *next;
};
struct node *head=NULL,*temp,*newnode;
void insert()
{
struct node *newnode=(struct node*)malloc(sizeof(struct node));
printf("\n Enter the number: ");
scanf("%d",&newnode->data);
printf("\n Enter the priority:");
scanf("%d",&newnode->pri);
if(head==NULL || newnode->pri<head->pri)
{
newnode->next=head;
head=newnode;
}
else{
    temp=head;
    while(temp->next!=NULL&&temp->next->pri<=newnode->pri)
        temp=temp->next;
    newnode->next=temp->next;
    temp->next=newnode;
}
}
void delete()
{
    if(head == NULL)
        printf("\nNULL\n");
    else {
        int n = head->data;
        head= head->next;
        printf("\n%d is deleted from the beginning successfully\n", n);
    }
}
void peek()
{
    if(head == NULL)
        printf("\nNULL\n");
    else {
            printf("\n the front element is %d with priority %d",head->data , head->pri);

}
}
void display()
{
    temp=head;
    printf("\n The datas are:");
    while(temp!=0)
    {
        printf("\n Priority:%d  Data:%d",temp->pri,temp->data);
        temp=temp->next;

    }
}
int main()
{
int choice=0;

do
{
printf("\n 1.insert \n 2.peek \n 3.delete \n 4. display \n 5. exit");
printf("\n enter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
    insert();
    break;
case 2:
    peek();
    break;
case 3:
    delete();
    break;
case 4:
    display();
    break;
case 5:
    exit(0);
default:
    printf("\n Invalid choice");
    break;
}
}while(choice!=5);
return 0;
}
