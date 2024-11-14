#include<stdio.h>
int main()
{
	char a[66];
	int i;
	gets(a);
	for(i=0;i<=65;i++)
	{
	 if(a[i]==90) a[i] = 66;
	else if(a[i]==89) a[i] = 65;
	else if(a[i]==92) a[i] = 92;
	else if(a[i]==122) a[i] = 98;
	else if(a[i]==121) a[i] = 97;
	else if((a[i]>=97)&&(a[i]<=120)) a[i] = a[i]+2;
	else if((a[i]>=65)&&(a[i<=88]))  a[i] = a[i]+2;
	}
	
	puts(a); 
	return 0;
	
}
