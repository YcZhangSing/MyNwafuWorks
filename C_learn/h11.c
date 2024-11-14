#include<stdio.h>
int main()
{
	int i=0,j=0,a[20][20]={0};
	a[0][0]=1;
	for(i=1;i<20;i++)
	{
		for(j=1;j<20;j++)
		{
			a[i][j]=a[i-1][j] +a[i-1][j+1];
			
		}
	}
	
	int n=0;
	while(scanf("%d,&n"))
	{
		for(i=n-1;i>=0;i--)
		{
			for(j=n-1;j>=0;j--)
			{
				if(a[i][j]==0) printf("   ");
				else
				{
					printf("%3d",a[i][j]);
				}
				if(j==0) printf("\n");
			}
		}
	}
	return 0;	
 } 
