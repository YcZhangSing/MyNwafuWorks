#include<stdio.h>
int main()
{
	float a,b,x,y,z,l;
	printf("请输入两个实数，按回车继续："); 
	scanf("%f %f",&a,&b);
	x=a+b;
	y=a-b;
	z=a*b;
	printf("两数和为%.2f\n",x);
	printf("两数差为%.2f\n",y);
	printf("两数积为%.2f\n",z);
	if(b=0) printf("两数相除，被除数不得为0");
	else l=a/b;
	printf("两数商为%.2f\n",l); 
	return 0;
}
