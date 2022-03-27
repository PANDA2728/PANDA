#include<stdio.h>
#include<stdlib.h>
struct node
{
int id;
struct node *next;
};
struct node *head,*temp,*newnode;
int main()
{
int n,k,count,i;
printf("\n Enter the number of players:");
scanf("%d",&n);
printf("\n Enter the number that every time the person got killed:");
scanf("%d",&k);
newnode=(struct node*)malloc(sizeof(struct node));
head=newnode;
newnode->id=1;
newnode->next=0;
temp=head;
for(i=2;i<=n;i++)
{
newnode=(struct node*)malloc(sizeof(struct node));
temp->next=newnode;
newnode->id=i;
newnode->next=head;
temp=temp->next;
}
temp=head;
for(count=n;count>1;count--)
{
for(i=0;i<k-1;++i)
{
temp=temp->next;
}
temp->next=temp->next->next;
}
printf("\n The winner is :%d",temp->id);
getch();
return 0;
}
