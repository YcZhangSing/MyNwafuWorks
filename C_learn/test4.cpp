#include<stdio.h>
#include<stdlib.h>
void g_swap(void* pa,void*pb,int size)
{
	char *vpa = (char*)pa;
	char *vpb = (char*)pb;
	int n=size;
	char *vpt = (char *)malloc(size);
	
	
	while (n--)
	*(vpt++) = *(vpb++);
	while (n--)
	*(vpa++)=*(vpb++);
	while (n--)
	*(vpb++)=*(vpt++);
 } 
int main()
{
	int a=3,b=9;
	printf("%d\n",b);
	g_swap(&a,&b,4);
	printf("%d",b);
	return 0;
 } 
