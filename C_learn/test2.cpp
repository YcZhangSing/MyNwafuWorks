#include<stdio.h>
int main()
{
	int b, a=11;
	int *pa=&a;
	b = pa[0];
	printf("%d",b);
	return 0;

}
