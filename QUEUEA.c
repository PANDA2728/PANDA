#include<stdio.h>
int a[100],max,rear=-1,front=-1,data;
 void insert()
{
    if(rear==max-1)
    {
        printf("\n The queue is full");
    }
    else{
    printf("\n Enter the data:");
    scanf("%d",&data);
    if(front==-1)
    {
            a[++rear]=data;
            ++front;
    }
    else
    {
    a[++rear]=data;
    }
    }
}
void delete()
{
    if(front==-1)
    {
        printf("\n The queue is empty");
    }
    else
    {
        printf("\n the deleted element is %d",a[front]);
        front++;
    }
}
void peek()
{
    if(front==-1)
    {
        printf("\n The queue is empty");
    }
    else
    {
        printf("\n The First element is %d",a[front]);
    }
}
void display()
{
    int temp=front;
    if(front==-1)
    {
        printf("\n The queue is empty");
    }
    else
    {
    while(temp<=rear)
    {
        printf("\n The elements are %d",a[temp]);
        temp=temp+1;
    }
    }
}
int main()
{
    int choice;
    printf("\n Enter the size of queue:");
    scanf("%d",&max);
    do
    {
    printf("\n 1.insert\n 2.Delete\n 3.Peek\n 4.Display\n 5.Exit");
    printf("\n Enter the choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        insert();
        break;
    case 2:
        delete();
        break;
    case 3:
        peek();
        break;
    case 4:
        display();
        break;
    case 5:
        exit(0);
    }
    }while(choice!=5);
return 0;
}
