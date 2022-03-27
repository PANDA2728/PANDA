#include<stdio.h>
int arr[26][26],size=3;
void printAllVertex()
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            printf("%5d ",arr[i][j]);
        }
        printf("\n");
    }
}
int not_visited(int waiting[],int k,int end_waiting)
{
    for(int i=0;i<=end_waiting;i++)
    {
        if(waiting[i]==k)
            return 0;
    }
    return 1;
}
void BFS()
{
    int q[10],vi[10],start=0;
    int i,j;
    int front=-1,frontq=0,rearq=-1;
    vi[++front]=start;
    q[++rearq]=start;
    while(rearq!=-1)
    {
        int cur=q[frontq];
        frontq++;
        if(frontq>rearq)
        {
            frontq=0;
            rearq=-1;
        }
        for(int k=0;k<=front;k++)
            printf("\n %d",vi[k]);
        printf("\nVisited %c\n", cur+65);
        for(i=0;i<size;i++)
        {
            if(arr[cur][i]==1)
            {
            if(not_visited(vi,i,front))
            {
                q[++rearq]=i;
                vi[++front]=i;
                printf("\n A");
            }
            }
        }
    }
}
void main()
{
    char val,val1;
    int n;
    while(1)
    {
        printf("\nEnter your choice \n 1.insert new vertex \n 2.insert new edge \n 3.BFS \n 4.display");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            printf("\nEnter no of vertex");
            scanf(" %d",&size);
            for(int i=0;i<size;i++)
                {
                    for(int j=0;j<size;j++)
                    {
                        arr[i][j]=0;
                    }
                }
            break;
        case 2:
            printf("\nEnter vertex and edge ");
            scanf(" %c",&val);
            scanf(" %c",&val1);
            int a=val-65,b=val1-65;
            arr[a][b]=arr[b][a]=1;
            break;
        case 3:
            BFS();
            break;
        case 4:
            printAllVertex();
            break;
        default:
            break;
        }
    }
}

