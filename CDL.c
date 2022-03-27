#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next, *prev;
};
struct node *head=0,*temp,*end=0;
int count=0;
void insert_begin() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter an element to insert at beginning: ");
    scanf("%d", &newnode->data);
    if(head==NULL)
  {
  head=end=newnode;
  head->next=newnode;
  head->prev=newnode;
  }
  else
  {
   newnode->next=head;
   head->prev=newnode;
   head=newnode;
   head->prev=end;
   end->next=head;
   }
}
void insert_end() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;

    printf("\nEnter an element to insert at end: ");
    scanf("%d", &newnode->data);
    if(head==NULL)
        insert_begin();
    else{
    newnode->prev=end;
    newnode->next=head;

    end->next = newnode;
    end = newnode;
    head->prev = end;

}
}
void insert_pos() {
    int pos, begin = 1;
       temp=head;
    printf("\nEnter position to insert: ");
    scanf("%d", &pos);
    while(temp!=end)
  {
  temp=temp->next;
  count++;
  }count++;

    if(pos < 1 || pos > count)
        printf("\nInvalid position\n");
    else if(pos == 1)
        insert_begin();
    else if(pos == count)
        {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));

        printf("\nEnter element to insert at position %d: ");
        scanf("%d", &newnode->data);
            temp=head;
            while(temp!=end)
            {
                temp=temp->next;
                }
                newnode->prev=temp->prev;
                newnode->next=temp;
                temp->prev->next=newnode;
                temp->prev=newnode;
        }

    else {
            temp=head;
        while (begin < pos - 1) {
            temp = temp->next;
            ++begin;
        }
        struct node *newnode = (struct node *)malloc(sizeof(struct node));

        printf("\nEnter element to insert at position %d: ");
        scanf("%d", &newnode->data);

        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        newnode->next->prev = newnode;
}
}
void delete_begin() {
    struct node *temp = head;
    int n;

    if(head == NULL)
        printf("\nList Empty\n");
    else {
        n = head->data;
        head = head->next;
        head->prev = end;
        end->next = head;

        printf("%d is deleted from the list\n", n);
    }
}

void delete_end() {
    struct node *temp = head;
    int n;
    if(temp == NULL)

        printf("\nList empty\n");
    else
    {


        while(temp->next != end){
            temp = temp->next;
        }

        n = temp->next->data;
        temp->next = head;
        free(end);
       // end->prev = NULL;
        end = temp;
        printf("\n%d is deleted from the list\n", n);

        }
}
void delete_pos() {
    int pos, n, begin = 1;
    printf("\nEnter position to delete: ");
    scanf("%d", &pos);
    temp=head;
 while(temp!=end)
  {
  temp=temp->next;
  count++;
  }count++;

    if(pos < 1 || pos > count)
        printf("\nInvalid position\n");
    else if(pos == 1)
        delete_begin();
    else if(pos == count)
        delete_end();
    else {
        temp = head;
        while(begin < pos) {
        temp = temp->next;
            begin++;
        }

        n = temp->data;
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        printf("\n%d is deleted from position %d\n", n, pos);
     }
}

void display()
{
temp=head;
while(temp!=end)
 {
  printf("\nThe values are %d",temp->data);
  temp=temp->next;
 }
 printf("\nThe values are %d",temp->data);
 }

void search() {
    struct node *temp = head;
    int ele, flag=0;
    if (temp == NULL)
        printf("\nNULL\n");
    else {
        printf("\nEnter the element to search: ");
        scanf("%d", &ele);
        while(temp != end) {
            if(temp->data == ele) {
                flag = 1;
                printf("\n%d is found in the list\n", ele);
                break;
            }
            temp = temp->next;
        }
        if(flag == 0)
            printf("%d is not found in the list\n", ele);
     }
}
int main() {
    int ch;
    while(1) {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert at any position\n4. Delete at beginning\n5. Delete at end\n6. Delete at any position\n7. Search\n8. Display\n9. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch) {
            case 1: insert_begin();
                    break;
            case 2: insert_end();
                    break;
            case 3: insert_pos();
                    break;
            case 4: delete_begin();
                    break;
            case 5: delete_end();
                    break;
            case 6: delete_pos();
                    break;
            case 7: search();
                    break;
            case 8: display();
                    break;
            case 9: exit(0);
            default: printf("\nInvalid choice\n");
        }
    }
    return 0;
}
