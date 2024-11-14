#include<stdio.h>
int main()
{
	int year=0,n=0;
	scanf("%d%d",&year,&n);
	char a[4]={0};
	sprintf(a,"%04d",year);
	puts(a);
	return 0;
}
