#include<stdio.h>
void swap(int *,int*);
int main()
{

	int a[10]={0},i,j,t=0;
	for(i=0;i<=9;i++)
	{
		scanf("%d",&a[i]);
	}
	
	
	
	for(i=0;i<9;i++)
	{
		for(j=0;j<10-i-1;j++)
		
		
			if(a[j]<a[j+1])
		{
			swap(&a[j],&a[j+1]);
		}
	}

	
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);		
	}
	return 0;
}

void swap(int *a,int *b)
{	

	int t=0;
	t=*a;
	*b=*a;
	*b=t;
	

}
