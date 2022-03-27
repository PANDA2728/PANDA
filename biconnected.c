#include<stdio.h>
int arr[26][26],size=3;
int count;
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
int BFS(int start,int a[26][26])
{
    int q[10],vi[10];
    int i,j;
    count=0;
    int front=-1,frontq=-1,rearq=-1;
    vi[++front]=start;
    q[++rearq]=start;
    frontq++;
    while(rearq!=-1)
    {
        int cur=q[frontq++];
        if(frontq>rearq)
        {
            frontq=0;
            rearq=-1;
        }
        printf("Visited %c\n", cur+65);
        count++;
        for(i=0;i<size;i++)
        {
            if(a[cur][i]==1)
            {
            if(not_visited(vi,i,front))
            {
                q[++rearq]=i;
                vi[++front]=i;
            }
            }
        }
    }
    printf("\n %d",count);
    return count;
}

void biconect()
{
int A[26][26];
int i,j,k,TOTAL;
int count=size;
for(k=0;k<size;k++){
		for(i=0;i<size;i++){
			for(j=0;j<size;j++){
			A[i][j]=arr[i][j];
			}
		}
		for(i=0;i<size;i++){
			for(j=0;j<size;j++){
				if(i==k || j==k)
				A[i][j]=0;
			}
		}
		if(k==0) {
			TOTAL=BFS(1,A);
		}
		else{
			TOTAL=BFS(0,A);
		}
		if(TOTAL != count-1){
			printf("\nTOTAL: %d\n",TOTAL);
			printf("\n It is not biconnected");
			return;
		}
	}
	printf("It is biconnected");
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
            printf("\nEnter start point: ");
            scanf(" %c",&val);
            a=val-65;
            int r=BFS(a,arr);
            break;
        case 4:
            printAllVertex();
            break;
        case 5:
            biconect();
            break;
        }
    }
}
