#include<stdio.h>
int main()
{
	int i,n,b,oh=0,jh=0,og=0,jg=0;
	
	scanf("%d",&n);
	
	getchar();
	
	for(i=0;i<n;i++);
	
		{scanf("%d",&b);
		if(b%2!=0) 
		               {
		jh=jh+b,jh++;}
		else 
		             {
		oh=oh+b,oh++;}
		}	
		printf("%d\n%d\n%d\n%d\n",jh,jg,oh,og); 
		return 0;
}
