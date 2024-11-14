#include<stdio.h>
int max(int a,int b)
{
	if(a<b) 
	{a^=b;
	 b^=a;
	 a^=b;
	}
	return a;
}
int main()
{
	int a[60];
	printf("请输入每个小朋友捡到的苹果数，输入-1结束：");
	for(int i=0;i<=59,i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==-1) a[i]=0;
	}
}
