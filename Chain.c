#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	int key;
	struct node *next;
}*temp;
int size,i,num,ch,j = 0;

void insert(struct node ht[], int size)
{
	printf("Enter the element: ");
	scanf("%d",&num);
	temp = ht[num%size].next;
	if(temp == 0)
	{
		struct node *nn;
		nn = (struct node*)malloc(sizeof(struct node));
		nn->data = num;
		nn->next = 0;
		ht[num%size].next= nn;
	}
	else
	{
		struct node *nn;
		nn = (struct node*)malloc(sizeof(struct node));
		nn->data = num;
		nn->next = 0;
		while(temp->next != 0)
			temp = temp->next;
		temp->next = nn;
		temp = nn;
	}
}

void search(struct node ht[], int size)
{
	printf("Enter the element to be searched:");
	scanf("%d",&num);
	if(ht[num%size].next->data == num)
		printf("Element exists at: %d\n",num%size);
	else if(ht[num%size].next->next != 0)
	{
		struct node *ptr;
		ptr = ht[num%size].next->next;
		while(ptr->data != num)
		{
			ptr = ptr->next;
		}
		printf("Element exists at %d\n",num%size);
	}
	else
	{
		printf("doesn't exist\n");
		return;
	}
}

void clear(struct node ht[], int size)
{
	printf("Enter the element to be deleted: ");
	scanf("%d",&num);
	i = num%size;
	temp = ht[i].next;
	if(temp->data == num)
	{
		printf("Element deleted is %d\n",num);
		ht[i].next = temp->next;
		free(temp);
	}
	else if(ht[i].data != num)
	{
		while(temp->next->data != num)
		{
			temp = temp->next;
		}
		printf("Deleted element is %d\n",num);
		temp->next = temp->next->next;
	}
}

void display(struct node ht[], int size)
{
	int i;
	printf("\nkey\tvalue\n");
	for(i=0; i<size; i++)
	{
		printf("%d\t",ht[i].key);
		struct node *ptr;
		ptr = ht[i].next;
		while(ptr != NULL)
		{
			printf("%d-->\t",ptr->data);
			ptr = ptr->next;
		}
		printf("\n");
	}
}
int main()
{
	printf("Enter the size of the table:");
	scanf("%d",&size);
	struct node hashtable[size];
	for(i=0;i<size;i++)
	{
        hashtable[i].next = NULL;
		hashtable[i].data = -1;
		hashtable[i].key = i;
	}
	printf("\n1.Insert\n2.Delete\n3.Search\n4.display\n5.Exit\n");
	do
	{
		printf("choose:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert(hashtable,size);
				break;
			case 2:
			    clear(hashtable,size);
				break;
			case 3:
				search(hashtable,size);
				break;
			case 4:
			    display(hashtable,size);
				break;
		}
	}while(ch!=5);
	printf("\n\nThe End\n\n");
}
