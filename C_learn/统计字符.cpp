#include<stdio.h>
int main()
{
	char a[100]={};
	int i=0,n,n1=0,n2=0,n3=0,n4=0;
	gets(a);
	for(i=0;a[i]!=0;i++);
	n=i;
	
	for(i=0;i<n;i++)
	{
		if(a[i]>=65 && a[i]<=90)
		{
			n1++;
		}
		else if(a[i]>=97 && a[i]<=122)
		{
			n2++;
		}
		else if(a[i]>=48 && a[i]<=57)
		{
			n3++;
		}
		else 
		{
			n4++;
		}
	}
	printf("%d\n%d\n%d\n%d\n",n1,n2,n3,n4);
	return 0;
 } 
