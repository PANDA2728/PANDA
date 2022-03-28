#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *link;
};

struct node *head=NULL,*newnode,*temp=NULL;
int count=0,delNum;

void insertBegin();
void insertEnd();
void insert_pos();
void deleteBegin();
void deleteEnd();
void deleteGivenValue();
void display();
int ch=0;

int main(){
	do{
	printf("\nEnter the operation to be performed");
	printf("\n1.Insert at the beginning\n 2.Insert at the end \n3.Insert after the given value \n4.Insert before the given value \n5.DElete at the beginning \n6.Delete at the end \n7.Delete the given value \n 8.Display \t9.exit");
	scanf("%d",&ch);
	switch(ch){
		case 1:{
			insertBegin();
			break;
		}
		case 2:{
			insertEnd();
			break;
		}
		case 3:{
			insert_pos();
			break;
		}
		case 4:{
			deleteBegin();
			break;
		}
		case 5:{
			deleteEnd();
			break;
		}
		case 6:{
			deleteGivenValue();
			break;
		}
		case 7:{
			display();
			break;
		}
		case 8:{
			printf("\n*******EXITING***********");

		}

	}
	}while(ch!=8);

}

void insertBegin(){
	newnode = (struct node*) malloc(sizeof(struct node));
	printf("\nEnter the value:\t");
	scanf("%d",&newnode->data);
	if(newnode == NULL){
		printf("Overflow");
	}
	else{
		if(head == NULL){
			newnode->link = NULL;
			head = newnode;
			printf("\n Node inserted");
			count++;}
			else
			{
			newnode->link=head;
			head=newnode;
			printf("\n node inserted");}
            count++;
	}
}

void insertEnd(){
	newnode = (struct node*) malloc(sizeof(struct node));
	printf("\nEnter the value\t");
	scanf("%d",&newnode->data);
	newnode->link = NULL;

		if(head == NULL){

			head = newnode;
			printf("\n Node inserted");
			count++;
		}
		else{
			temp = head;
			while(temp->link != NULL){
				temp=temp->link;
			}
			temp->link = newnode;
			printf("\n Node inserted");
			count++;
		}
}
void insert_pos() {
    int pos, begin=1;;

    printf("Enter position to insert: ");
    scanf("%d", &pos);

    if(pos < 1 || pos > count)
        printf("\nInvalid position\n");
    else {
     newnode = (struct node *)malloc(sizeof(struct node));
     temp = head;
        printf("Enter element to insert at position %d: ", pos);
        scanf("%d", &newnode->data);

        newnode->link = NULL;

        prev = temp;

        while(temp != NULL && begin < pos) {
            prev = temp;
            newnode = temp->link;
            begin++;
        }

        if(begin == 1) {
            newnode->link = head;
            head = newnode;
        }
        else if(pos == begin) {
            prev->link = newnode;
            newnode->link = temp;
        }
        ++count;
    }
}
void deleteBegin(){
    head=head->link;
	printf("\back begin deleted\n");

}

void deleteEnd(){

	temp=head;

  while(temp->link->link!=NULL)
  {
	temp=temp->link;

  }
  temp->link=NULL;

  printf("ending node deleted");
}

void deleteGivenValue(){
	temp= head;
	printf("\nEnter the number to search and delete \n");
	scanf("%d",&delNum);
	if(head->data == delNum){
		head= head->link;
	}
	else{

	while( temp->link->data != delNum ){
		temp = temp->link;
	}
			temp->link = temp->link->link;
			}
}

void display(){
	temp=head;
	while(temp!=NULL)
	{
		printf("\n %d\n" ,temp->data);
		temp=temp->link;
	}
}


