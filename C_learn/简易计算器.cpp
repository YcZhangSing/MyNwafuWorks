#include<stdio.h>
int main()
{
	float a,b,x,y,z,l;
	printf("����������ʵ�������س�������"); 
	scanf("%f %f",&a,&b);
	x=a+b;
	y=a-b;
	z=a*b;
	printf("������Ϊ%.2f\n",x);
	printf("������Ϊ%.2f\n",y);
	printf("������Ϊ%.2f\n",z);
	if(b=0) printf("�������������������Ϊ0");
	else l=a/b;
	printf("������Ϊ%.2f\n",l); 
	return 0;
}
