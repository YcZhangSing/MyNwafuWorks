#include<stdio.h>
#include<stdlib.h> 
void Swap(void *vp1,void *vp2,int size)//���������������ݵ�void���͵�ָ�룬size������Ҫ�����������͵��ֽ�����
{
 
	char  *tmp = (char *)malloc(size);//��̬�Ĵ���һ��char����size�ֽڴ�С��ָ��
	char *p1 = (char *)vp1;//���β�ǿתΪchar*
	char *p2 = (char *)vp2;//���β�ǿתΪchar*
	int i;
	for(i=0;i<size;i++)//��ָ��p1�е�����һ��һ���ֽڵĴ���tmp��
	{
		tmp[i] = p1[i];
	}
 
	for(i=0;i<size;i++)//��ָ��p2�е�����һ��һ���ֽڵĴ���p1��
	{
		p1[i] = p2[i];
	}
 
	for(i=0;i<size;i++)//��ָ��tmp�е�����һ��һ���ֽڵĴ���p2��
	{
		p2[i] = tmp[i];
	}
	free(tmp);//�ͷŶ�̬�ڴ�
	
}
int main()
{
	int c=9;
	int a=6;
	printf("%x\n%x\n",c,a);
	Swap(&c,&a,4);
	printf("%x\n%x",&c,&a);
	return 0;
}
