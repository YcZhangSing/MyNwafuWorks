#include<stdio.h>
int main() 
{
	char c[100]={0};
	int i=0;
	while(c[i] != EOF)
	{
		scanf("%c",&c[i]);
		i++;
	 }
	 puts(c);
	 
	 return 0;
	 
	
	
}

