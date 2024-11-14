#include<stdio.h>
int main()
{
	int i,j,n;
	char ch,ch0;
	ch = getchar();
	ch0 = getchar();
	scanf("%d",&n);
	for(i=0;i<n;i++)    //大循环 
	{
	for (j=0;j<(n-i-1);j++) //小循环输出规律性变化的空格 
		printf(" ");
	for(j=0;j<(2*i+1);j++)//小循环输出规律性变化的ch 
		printf("%c",ch);
		printf("\n");
	
	}
	return 0;
}
