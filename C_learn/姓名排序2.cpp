#include<stdio.h>
#include<string.h>
int main()
{
	char a[10][10]={},t;
	char b[10][10]={};
	int i=0,j=0;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{	
	       scanf("%c",&a[i][j]);
	       if(a[i][j]=='\n') break;
		}
		if(i==9 && j==6) break;
	}
	
	
	for(i=0;i<9;i++)
	{
		for(j=0;j<6;)
		{
			if(a[i][j]==a[i+1][j]) j++;
			else if(a[i][j]<a[i+1][j])
			{
				strcpy(b[i],a[i]);
				strcpy(a[i],a[i+1]);
				strcpy(a[i+1],b[i]);
				
			}
			
		}
	}
	for(i=0;i<9;i++)
	{
		puts(a[i]);
		printf("\n");
	}
	return 0;
 } 
