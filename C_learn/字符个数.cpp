#include<stdio.h>
int main()
{
	int i,j,n;
	char ch,ch0;
	ch = getchar();
	ch0 = getchar();
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	for (j=0;j<(n-i-1);j++)
		printf(" ");
	for(j=0;j<(2*i+1);j++)
		printf("%c",ch);
		printf("\n");
	
	}
	return 0;
}
