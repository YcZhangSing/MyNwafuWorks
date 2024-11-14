#include<stdio.h>
int main()
{
		int a,b,i;
	

	scanf("%d %d",&a,&b);
	for(a;a<=b;a++)
	{if((a-8)%10==0) i=i+1;
	else if(a=a/10,a=(int)a,a>10 && (a-8)%10==0) i=i+1;
	else i=i;
	
	 }
	 printf("%d",i);
	 return 0;
}
