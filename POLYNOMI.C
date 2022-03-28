#include<stdio.h>
#include<stdlib.h>
struct node
{
int coeff;
int expo;
struct node*link;
};
void insert();
void display();
struct node*head=0,*temp,*newnode;
int main()
{
int choice;

while(1)
{
printf("\n press 1.INSERT 2.DISPLAY 3.EXIT");
scanf("%d",&choice);

switch(choice)
{
case 1:
insert();
break;
case 2:
display();
break;
case 3:
exit(0);
}
}
}
void insert()
{
int co,ex;
printf("\nEnter the coefficient value: ");
scanf("%d",&co);
printf("\nEnter the exponent value: ");
scanf("\n%d",&ex);
newnode=(struct node*)malloc(sizeof(struct node));
if(head==0)
{
newnode->link=0;
head=temp=newnode;
newnode->coeff=co;
newnode->expo=ex;
}
else
{
temp->link=newnode;
newnode->link=0;
newnode->coeff=co;
newnode->expo=ex;
temp=temp->link;
}
printf("\n The element is inserted successfully");
}
void display()
{
temp=head;
while(temp->link!=0)
{
printf("%dx^%d+",temp->coeff,temp->expo);
temp=temp->link;
}
if(temp->expo==1&&temp->link!=0)
{
printf("%dx+",temp->coeff);
temp=temp->link;
}
else if(temp->expo==1&&temp->link==0)
{
 printf("%dx",temp->coeff);
temp=temp->link;
}
else if(temp->expo==0&&temp->link==0)
{
    printf("%d",temp->coeff);
temp=temp->link;
}
}



