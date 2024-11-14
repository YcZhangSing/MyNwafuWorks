#include<stdio.h>
int F(int *,void (*f)(int *));
void m(int *);
int n(int *);

int main()
{
	int a=9;
	F(&a,m);
	printf("%d",a);
	return 0;
 } 
 int F(int *pa,void (*f)(int *))
 {
 	f(pa);
 }
 
 
 
 
void m(int *pa)
{
	*pa = *pa +1;
}
