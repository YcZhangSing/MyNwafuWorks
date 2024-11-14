#include<stdio.h>
int f(unsigned int n)
{
		if(n<=3){
			return 1;
		}
		else if(n==4){
		return 2;
		}
		else {
			return (f(n-1)+f(n-1)-f(n-2)+f(n-3)-f(n-4));
		}
 } 
 int main()
 {
 	unsigned int n;
 	scanf("%d",&n);
 	printf("%d\n",f(n));
 	return 0;
 }
 	
