#include<stdio.h>
#include<string.h>

int main()
{

int num=12345;
 char *str={0}; 
 
unsigned u_num; /* ��¼�޷�����ֵ���м���� */
	int i = 0, k;


	
		u_num = (unsigned)num;   /* ������� */
	

	/* �ֽ���������λ��ע���λ���ֵ�˳����ʵ���෴ */
	do
	{
		/* �����ַ���������ʵ������ת�� */
		str[i++] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[u_num % (unsigned)10];
		u_num /= 10;
	}
	while(u_num);
	
	str[i] = '\0'; /* ��ֹ�ַ� */

		printf("%s",str);


}


