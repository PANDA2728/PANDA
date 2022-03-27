#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node*next;
};
typedef struct node node;
node*start=NULL,*rear=NULL,*temp,*newnode;
int max,count=0;
void insertright(){
if(count == max){
 printf("\nThe Queue is full/Overflow\n");
}
else if(start==NULL && rear==NULL){
 start = (node*)malloc(sizeof(node));
 rear = start;
 printf("\nEnter the data : ");
 scanf("%d",&start->data);
 start->next = NULL;
 count++;
}
else{
 rear->next=(node*)malloc(sizeof(node));
 rear = rear->next;
 printf("\nEnter the data : ");
 scanf("%d",&rear->data);
 rear->next = NULL;
 count++;
}
}
void insertleft(){
if(count == max){
 printf("The Queue is FULL");
}
else {
 newnode=(struct node*)malloc(sizeof(struct node));
 newnode->next=start;
 start=newnode;
 printf("Enter the data:");
 scanf("%d",&newnode->data);
 count++;
 }
}
void display(){
int count1 =1;
if(start==NULL){
 printf("\nThe Queue is Empty");
}
else{
 temp = start;
 printf("\n start ->%u",start);
 while(temp!=NULL){
 printf("\n Node:%d",count1);
 printf("\n temp->%u",temp);
 printf("\n temp->data-->%d",temp->data);
 printf("\n temp->next-->%u",temp->next);
 temp= temp->next;
 count1++;
 }
 printf("\nrear-->%u",rear);
}
}
void deleteright(){
temp=start;
if(start==NULL){
 printf("\nThe Queue is Empty");
}
else{
 while(temp->next!=rear){
 temp = temp->next;
 }
rear=temp;
rear->next=NULL;
}
}
void deleteleft(){
if(start==NULL){
 printf("\nThe Queue is Empty");
}
else{
 start= start->next;
}
}
void input_deque(){
int choice1;
printf("\nEnter the operation do you like to do 1)insert at right 2)delete at right 3)delete at left 4)Display 5)End ");
scanf("%d",&choice1);
while(choice1!=5){
 switch(choice1){
 case 1:
 insertright();
 break;
 case 2:
 deleteright();
 break;
 case 3:
 deleteleft();
 break;
 case 4:
 display();
 break;
 default:
 printf("Invalid Input");
 break;
 }
printf("\nEnter the operation do you like to do 1)insert at right 2)delete at right 3)delete at left 4)Display 5)End ");
scanf("%d",&choice1);
}
}
void output_deque(){
int choice1;
printf("\nEnter the operation do you like to do 1)insert at right 2)insert at left 3)delete at right 4)Display 5)End ");
scanf("%d",&choice1);
while(choice1!=5){
 switch(choice1){
 case 1:
 insertright();
 break;
 case 2:
 insertleft();
 break;
 case 3:
 deleteright();
 break;
 case 4:
 display();
 break;
 default:
 printf("Invalid Input");
 break;
 }
printf("\nEnter the operation do you like to do 1)insert at right 2)insert at left 3)delete at right 4)Display 5)End ");
scanf("%d",&choice1);
}
}
int main(){
int choice;
printf("\nEnter the max of data in the queue:");
scanf("%d",&max);
printf("Enter the operation do you like to do 1)input deque 2)output deque 3)End");
scanf("%d",&choice);
while(choice!=3){
 switch(choice){
 case 1:
 input_deque();
 break;
 case 2:
 output_deque();
 break;
 default:
 printf("Invalid Input");
 break;
}
printf("\nEnter the operation do you like to do 1)input deque 2)output deque 3)End");
scanf("%d",&choice);
}
}
