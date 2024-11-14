#include<stdio.h>
#define N 5
int sum_a(int a[N][N]); 
int sum_b(int a[N][N]); 
int main()
{
	int a[N][N]={0},sum1=0,sum2=0,i=0,j=0;
	for(i=0;i<=N-1;i++)
	{
		for(j=0;j<=N-1;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	sum1 = sum_a(a);
	sum2 = sum_b(a);
	
	printf("%d %d",sum1,sum2);
	return 0;
	
 } 
 
 int sum_a(int a[N][N])
 {
 	int sum1=0,i=0,j=0;
 	for(i=0;i<N;i++)
 	{
 		for(j=0;j<N;j++)
 		{
 			if(j==i)
 			sum1=sum1+a[i][j];
		 }
	 }
 	
 	return sum1;
 }
 
 int sum_b(int a[N][N])
 {
 	int sum2=0,i=N-1,j=0;
 	for(i=N-1;i>=0;i--)
 	{
 		sum2=a[i][j]+sum2;
 		j++;
	}
 	return sum2;
 }
