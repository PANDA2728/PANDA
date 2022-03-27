#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
struct node{
char vertex;
struct node* next;
};
struct node* dum;

struct graph{
int numvertexes;
struct node adjlist[100];
char visited[100];
};


struct node* createnode(char v){
    struct node * ne=(struct node*)malloc(sizeof(struct node));
    ne->vertex=v;
    printf("\n The data %c ",v);
    ne->next=NULL;
    return ne;
}

struct graph* creategraph(int v)
{
    int i;
    char vert;
    struct graph * g=(struct graph*)malloc(sizeof(struct node));
    g->numvertexes=v;
    for(i=0;i<v;i++)
    {
        printf("\n Enter the Vertex:");
        scanf(" %c",&vert);
        g->adjlist[i].vertex=vert;
        g->adjlist[i].next=NULL;

    }

    return g;
}

void addedge(struct graph* g,char src,char dst)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->vertex=dst;
    temp->next=NULL;
    printf("\n The Data:%c",dst);
    int i;
    printf("\n The Data:%c",dst);
    for(i=0;i<g->numvertexes;i++)
    {
        printf("\n The data");
        if(g->adjlist[i].vertex==src)
        {
            dum=g->adjlist[i].next;
            printf("\n The data");
        }
    }
    printf("\n The data %c",dum->vertex);
    printf("\n The data");
        while(dum->next!=NULL)
        {
            dum=dum->next;
        }
        dum->next=temp;
        temp->next=NULL;

}

int isEmpty(struct queue* q) {
  if (q->rear == -1)
    return 1;
  else
    return 0;
}

struct queue* createQueue() {
  struct queue* q = malloc(sizeof(struct queue));
  q->rear = -1;
  q->front=-1;
  return q;
}

void enqueue(struct queue* q,int v)
{
    if(q->rear==SIZE-1)
    {
        printf("\n Queue is Full");
    }
    else{
    if(q->front==-1)
        q->front=0;
    q->rear++;
    q->qu[q->rear]=v;
    }
}

int dequeue(struct queue *q)
{
    char item;
    if (isEmpty(q)) {
    printf("Queue is empty");
    item = -1;
  }
  else {
    item = q->qu[q->front];
    q->front++;
//    if (q->front > q->rear) {
//      q->front = q->rear = -1;
//    }
  }
  return item;
}

void BFS(struct graph* graph, int startVertex) {
  struct queue* q = createQueue();
  int i=0,j=0;
  graph->visited[i] = startVertex;
  enqueue(q, startVertex);

  while (!isEmpty(q)) {
    char currentVertex = dequeue(q);
    printf("Visited %c\n", currentVertex);

     struct node *dum=NULL;
    for(i=0;i<graph->numvertexes;i++)
    {
        if(graph->adjlist[i].vertex==startVertex)
        {
            dum=graph->adjlist[i].next;
        }
    }
 while (dum!=NULL) {
     int flag=0;
      int adjVertex = dum->vertex;
      for(j=0;j<graph->numvertexes;j++)
      {
          if(graph->visited[j]==adjVertex)
          {
              flag=1;
              break;
          }
      }
      if(flag==0)
      {
          graph->visited[j] = adjVertex;
          enqueue(q, adjVertex);

      }
      dum = dum->next;
    }
  }
}


void display(struct graph* g)
{
    int i;
    struct node* j;
    printf("\nVERTEX\tAdjucent Vertex");
    for(i=0;i<g->numvertexes;i++)
    {

        printf("\n%c",g->adjlist[i].vertex);
        struct node* temp=g->adjlist[i].next;
        while(temp!=NULL)
        {
            printf("\t%c-->",temp->vertex);
            temp=temp->next;
        }
    }
}

int main() {
    int ch;
    char v;
    char b;
    int t;
do{
printf("\n 1.Insert Vertices \n 2.Insert Edges \n 3.BSF \n 4.Display \n 5.EXIT");
scanf("\n%d",&ch);
switch(ch)
{
case 1:
    printf("\n Enter the Number of vertices:");
    scanf("%d",&t);
    struct graph* graph = creategraph(t);
    break;
case 2:
    printf("\n Enter The Source:");
    scanf(" %c",&v);
    printf("\n Enter The Destination:");
    scanf(" %c",&b);
    addedge(graph,v,b);
    break;
case 3:
    printf("\n Enter The Start Point:");
    scanf(" %c",&v);
    BFS(graph, v);
    break;
case 4:
    display(graph);
    break;
case 5:
    exit(0);
    break;


}
}while(ch!=5);
}














