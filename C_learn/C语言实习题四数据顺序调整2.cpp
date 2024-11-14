#include<stdio.h>
#define N 10
void swap_m(int*);
int main()
{
	int i,j;
	int a[N]={0};
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	
	swap_m(a);
	
	for(j=0;j<N;j++)
	{
		printf("%d ",a[j]);
	
	}
	return 0;
}
void swap_m(int*a)
{
	int i,t,d1,d2,x1,x2;
	d1=a[0];
	x1=a[0];
	d2=0;
	x2=0;
	for(i=0;i<N;i++)
	{
		if(a[i]>d1)
		{
			d1=a[i];
			d2=i;
		}
		else if(a[i]<x1)
		{
			x1=a[i];
			x2=i;
		}
	}
     t=*a;
     *a=*(a+d2);
     *(a+d2)=t;
     
     t=*(a+9);
     *(a+9)=*(a+x2);
     *(a+x2)=t;
 }
