#include<stdio.h>
int main()
{int a,b,t,s,y;
	
	scanf("%d%d",&a,&b);
	s=a*b;
	do
	{
	y=a%b;
	t=a;
	a=b;
	b=t;
	b=y;
    }
	
	while (y==0);
	printf("%d\n%d\n%d\n",a,b,y);
	printf("%d\n%d\n",a,s/b);/*������ֳ������Ҫ����Ƿ��б�����Ϊ��������*/ 
        
	return 0;
}
