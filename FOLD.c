#include<stdio.h>
int arr[100],size;
int index(int a,int w,int e)
{
int j,m=1,n,i=0,c=0,s;
w=w/2;
while(i<w)
{
    m=m*10;
    i++;
}
printf("\n %d",m);
for(j=0;j<2;j++)
{
    s=a%m;
    c+=s;
    a=a/m;
}
  printf("\n %d",c);

n=c%m;
printf("\n %d",n);
return n;

}
int main()
{
int k,ch,data,in,a,count;
printf("\n The Enter The size of array:");
scanf("%d",&size);
do
{
printf("\n1.Insert \n2.search \n3.exit");
scanf("\n%d",&ch);
int f=size-1;
while(f>0)
{
    f=f/10;
    k++;
}

switch(ch)
{
case 1:
printf("\n Enter the Number To be Inserted in the table");
scanf("\n%d",&data);
int m=data;
  count=0;
while(m>0)
{

    m=m/10;
    count++;
}
printf("\n %d",count);
in=index(data,count,k);
if(arr[in]==NULL)
arr[in]=data;
else
printf("\n Collision Occurs");
break;
case 2:
printf("\n Enter the Number To be searched in the table");
scanf("%d",&a);
m=a;
count=0;
while(m>0)
{

    m=m/10;
    count++;
}
in=index(a,count,k);
if(arr[in]==a)
{
printf("\n The number %d is present in the array at index %d",a,in);

}
else
{
printf("\n The number %d is not present in the array");
}
break;
}
}while(ch!=3);
}
