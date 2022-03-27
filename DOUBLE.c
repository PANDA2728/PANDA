#include<stdio.h>
#include<stdlib.h>

	struct node {
	int data;
	struct node *next;
	struct node *prev;
      };
      struct node *newnode, *head=NULL,*temp;


void insertBegin();
void insertEnd();
void insertMiddle();
void deleteBegin();
void deleteLast();
void deleteMiddle();
void display();
void exit();

int main()
 {
 int choice,count=0;
 printf("\t\t----DOUBLY LINKED LIST----\n ");
 printf("\n 1.InsertatFirst \t2.Insertatend \n3.Insertatmiddle \t4.Deleteatfirst \t5.Deleteatlast \n6.Deleteatmiddle \t7.Exit");
do
{
 printf("\t\nEnter your choice:");
 scanf("%d",&choice);
 switch(choice)
 {
	case 1:
		insertBegin();
		count++;
		break;
	case 2:
		insertEnd();
		count++;
		break;
	case 3:
		insertMiddle();
		count++;
		break;
	case 4:
		deleteBegin();
		count--;
		break;
    case 5:
		deleteLast();
		count--;
		break;
    case 6:
		deleteMiddle();
		count--;
		break;
    case 7:
		display();
		break;
    case 8:
		exit(0);
    default:
        {
		printf("Enter the correct choice\n");
	       }
       }
       }while(choice!=9);
       getch();
       return 0;
       }

 void insertBegin()
  {
  newnode=(struct node*)malloc(sizeof(struct node)) ;
  printf("\nEnter the number to add first");
  scanf("%d",&newnode->data);
  if(head==NULL)
  {
   head=newnode;
   head->next=NULL;
   head->prev=NULL;
  }
  else
  {
  head->prev=newnode;
  newnode->next=head;
  head=newnode;
  head->prev=NULL;
  }
  }

 void insertEnd()
 {
  newnode=(struct node*)malloc(sizeof(struct node)) ;
  printf("\nEnter the number to add last");
  scanf("%d",&newnode->data);
  temp=head;
  while(temp->next!=NULL)
  {
  temp=temp->next;
  }
  newnode->prev=temp;
  temp->next=newnode;
  newnode->next=NULL;
}

void insertMiddle()
{
 int i=1,pos,count;
 temp=head;
 printf("\nEnter the position to add");
 scanf("%d",&pos);

 if(pos>count)
 {printf("\nPosition Invalid");}

  else if(pos==1)
  {
  insertBegin();
      }
    else if(pos==count+1)
  {
  insertEnd();
      }

  else
  {

  newnode=(struct node*)malloc(sizeof(struct node)) ;
  printf("\nEnter the data to add:");
  scanf("%d",&newnode->data);
  temp=head;
  while(i<pos-1)
 {
 temp=temp->next;
 i++;
 }
  newnode->next=temp->next;
  newnode->prev=temp;
  temp->next=newnode;
  newnode->next->prev=newnode;
  }
  }

void deleteBegin()
{
 if(head==NULL)
 {printf("\nNothing to delete");}
 else
 {
  head=head->next;
  head->prev=NULL;
  free(temp);
  }
  }

void  deleteLast()
{
temp=head;
while(temp->next->next!=NULL)
{
temp=temp->next;
}
temp->next->prev=0;
temp->next=0;
 }
void deleteMiddle()
{
   int i=1,pos,count;
   temp=head;
   while(temp!=0)
 {
 temp=temp->next;
 count++;
 };
   printf("\nEnter the position to delete");
   scanf("%d",&pos);
   if(pos>count)
   {
   printf("\nUnable to delete");
   }
   else
   {
   temp=head;
    while(i<pos)
 {
 temp=temp->next;
 i++;
 }
   temp->prev->next=temp->next;
   temp->next->prev=temp->prev;
   free(temp);
   }
}
void display()
{
temp=head;
while(temp!=NULL)
 {
  printf("\nThe values are %d",temp->data);
  temp=temp->next;
 }
 }
