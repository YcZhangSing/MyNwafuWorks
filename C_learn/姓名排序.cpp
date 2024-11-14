#include<stdio.h>
int main()
{
	char a[10][10]={0},t;
	int i=0,j=0;
	for(i=0;i<10;i++)
	{
		for(j=0;j<5;j++)
		{	
	       scanf("%c",&a[i][j]);
		}
	}
	
	for(i=0;i<9;i++)
	{
		for(j=0;j<6;)
		{
			if(a[i][j]==a[i+1][j]) j++;
			else if(a[i][j]<a[i+1][j])
			{
				t=a[i][0];
				a[i][0]=a[i+1][0];
				a[i+1][0]=t;
				t=a[i][1];
				a[i][1]=a[i+1][1];
				a[i+1][1]=t;
				t=a[i][2];
				a[i][2]=a[i+1][2];
				a[i+1][2]=t;
				t=a[i][3];
				a[i][3]=a[i+1][3];
				a[i+1][3]=t;
				t=a[i][4];
				a[i][4]=a[i+1][4];
				a[i+1][4]=t;
				
			}
			
		}
	}
	for(i=0;i<9;i++)
	printf("%s",a[i]);
 } 

