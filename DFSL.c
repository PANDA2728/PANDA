#include<stdio.h>
#include<stdlib.h>
#define SIZE 40
struct queue {
  int items[SIZE];
  int rear;
};


struct node{
int vertex;
struct node* next;
};


struct graph{
int numvertex;
struct node** adjlist;
int* visited;
};


int isEmpty(struct queue* q) {
  if (q->rear == -1)
    return 1;
  else
    return 0;
}


struct queue* createQueue() {
  struct queue* q = malloc(sizeof(struct queue));
  q->rear = -1;
  return q;
}


struct node* createnode(int v)
{
    struct node * ne=(struct node*)malloc(sizeof(struct node));
    ne->vertex=v;
    ne->next=NULL;
    return ne;
}


struct graph* creategraph(int v)
{
    struct graph * g=(struct graph*)malloc(sizeof(struct node));
    g->numvertex=v;
    g->adjlist=malloc(v*sizeof(struct node));
    g->visited=malloc(v*sizeof(int));
    int i;
    for(i=0;i<v;i++)
    {
        g->adjlist[i]=NULL;
        g->visited[i]=0;
    }
    return g;
}


void addedge(struct graph* g,int src,int dst)
{
    struct node *temp=createnode(dst);
    temp->next=g->adjlist[src];
    g->adjlist[src]=temp;
    temp=createnode(src);
    temp->next=g->adjlist[dst];
    g->adjlist[dst]=temp;
}


void enqueue(struct queue* q,int v)
{
    if(q->rear==SIZE-1)
    {
        printf("\n Queue is Full");
    }
    else{
    q->rear++;
    q->items[q->rear]=v;
    }
}


int dequeue(struct queue *q)
{
    int item;
    if (isEmpty(q)) {
    printf("Queue is empty");
    item = -1;
  }
  else {
    item = q->items[q->rear];
    q->rear--;
  }
  return item;
}


void BFS(struct graph* graph, int startVertex) {
  struct queue* q = createQueue();

  graph->visited[startVertex] = 1;
  enqueue(q, startVertex);

  while (!isEmpty(q)) {
    int currentVertex = dequeue(q);
    printf("Visited %c\n", currentVertex+65);

    struct node* temp = graph->adjlist[currentVertex];

    while (temp) {
      int adjVertex = temp->vertex;

      if (graph->visited[adjVertex] == 0)
        {
            graph->visited[adjVertex] = 1;
            enqueue(q, adjVertex);
      }
      temp = temp->next;
    }
  }
}


void display(struct graph* g)
{
    int i;
    struct node* j;
    printf("\nVERTEX\tAdjucent Vertex");
    for(i=0;i<g->numvertex;i++)
    {
        printf("\n%c",i+65);
        struct node* temp=g->adjlist[i];
        while(temp!=NULL)
        {
            printf("\t%c-->",temp->vertex+65);
            temp=temp->next;
        }
    }
}


int main() {
    int ch;
    char v;
    char b;
    int t,s,d;
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
    s=v-65;
    d=b-65;
    addedge(graph,s,d);
    break;
case 3:
    printf("\n Enter The Start Point:");
    scanf(" %c",&v);
    s=v-65;
    BFS(graph, s);
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
