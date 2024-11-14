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
	int i,j,max,min,max_num,min_num,t;
	max=a[0];
	min=a[0];
	max_num=0;
	min_num=0;
	for(i=0;i<10;i++)
	{
		if(max<a[i])
		
		{
			max=a[i];
			max_num=i;
		}
	}
	for(j=0;j<10;j++)
	{
		if(min>a[j])
		
		{
			min=a[j];
			min_num=j;
		}
	}
	t=*(a);
	*a=max;
	*(a+i)=t;
	
	t=*(a+N-1);
	*(a+N-1)=min;
	*(a+j)=t;
}
