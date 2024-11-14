#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void generic_Swap(void *vp1, void *vp2, int size)
{
    char *tmp = (char *)malloc(size);
    memcpy(tmp, vp1, size);
    memcpy(vp1, vp2, size);
    memcpy(vp2, tmp, size);
}
int main()
{
	int a=9,b=6;
	
	generic_Swap(&a,&b,sizeof(a));
	
	printf("%d\n%d\n",a,b);
	return 0;
}
