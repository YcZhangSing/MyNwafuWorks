#include<stdio.h>
int main()
{
	int i,j,n;
	char ch,ch0;
	ch = getchar();
	ch0 = getchar();
	scanf("%d",&n);
	for(i=0;i<n;i++)    //��ѭ�� 
	{
	for (j=0;j<(n-i-1);j++) //Сѭ����������Ա仯�Ŀո� 
		printf(" ");
	for(j=0;j<(2*i+1);j++)//Сѭ����������Ա仯��ch 
		printf("%c",ch);
		printf("\n");
	
	}
	return 0;
}
