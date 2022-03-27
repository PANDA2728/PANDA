#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int q[SIZE], rear = -1, front = -1;

void sort() {
    int i, j, t;
    for(i=front; i!= rear; i=(i+1)%SIZE) {
        for(j=i+1; j!=rear; j=(j+1)%SIZE)
            if(q[i]>q[j]) {
                t = q[j];
                q[j] = q[i];
                q[i] = t;
            }
            if(q[i]>q[j]) {
                t = q[j];
                q[j] = q[i];
                q[i] = t;
}
}
}
void insert() {
    if((rear == SIZE-1 && front == 0) || (front == rear+1)) {
        printf("\nQueue full\n");
    }
    else if(rear == -1 && front == -1) {
        printf("\nEnter element to insert in the queue: ");
        scanf("%d", &q[++rear]);
        ++front;
    }
    else if(front != 0 && rear == SIZE-1) {
        rear = (rear + 1) % SIZE;
        printf("\nEnter element to insert in the queue: ");
        scanf("%d", &q[rear]);
        sort();
    }
    else {
        printf("\nEnter element to insert in the queue: ");
        scanf("%d", &q[++rear]);
        sort();
    }
}

void delete()
{
    if(front==-1)
    {
        printf("\n The queue is empty");
    }
    else if(front==rear)
    {
        printf("\n The deleted element is %d",q[front]);
        front=rear=-1;
    }
    else if(front==SIZE-1)
    {
        printf("\n The deleted element is %d",q[front]);
        front=0;
    }
    else
    {
        printf("\n The deleted element is %d",q[front]);
        front++;
    }
}
void display() {
    if(front == -1 && rear == -1)
        printf("\nQueue empty\n");
    else {
        int i;
        printf("\nQueue elements are:- ");
        for(i=front; i!=rear; i=(i+1)%SIZE)
            printf("%d ", q[i]);
        printf("%d ", q[i]);
        printf("\n");
    }
}

int main() {
    int ch;
    while(1) {
        printf("\n1. INSERT\n 2. DELETE\n3. DISPLAY\n4. EXIT\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("Invalid Choice");
        }
    }
    return 0;
}
