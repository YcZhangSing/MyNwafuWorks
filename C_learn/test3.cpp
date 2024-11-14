#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
void generic_Swap(void *pValue1, void *pValue2, size_t ValueSize)
{
    char *tmp = (char *)malloc(ValueSize);
    memcpy(tmp, pValue1, ValueSize);
    memcpy(pValue1, pValue2, ValueSize);
    memcpy(pValue2, tmp, ValueSize);
}
int main()
{
	double x=9.4;
	double y=6.4; 
	
	generic_Swap(&x,&y,4);
	printf("%lf\n%lf",x,y);
	return 0;
}
