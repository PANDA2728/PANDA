#include<stdio.h>
int arr[100];
int index(int a,int w)
{
int m=1,i=0,c;
c=a*a;
printf("\n%d",c);
while(i<w)
{
    m=m*10;
    printf("\nindex:%d",m);
    i++;
}
c=c/m;
c=c%m;
printf("index:",c);
return c;
}
int main()
{
int m,r=0,ch,data,in,a,size;
printf("\n Enter The Size:");
scanf("%d",&size);
m=size-1;
while(m>0)
{
    m=m/10;
    r++;
}
printf("%d",r);
do
{
printf("\n1.Insert \n2.search \n3.exit");
scanf("\n%d",&ch);
switch(ch)
{
case 1:
printf("\n Enter the Number To be Inserted in the table");
scanf("\n%d",&data);

in=index(data,r);
if(arr[in]==NULL)
arr[in]=data;
else
printf("\n Collision Occurs");
break;
case 2:
printf("\n Enter the Number To be Inserted in the table");
scanf("%d",&a);
in=index(a,r);
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

