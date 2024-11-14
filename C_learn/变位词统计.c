#include<stdio.h>
#include<string.h>

int main()
{

int num=12345;
 char *str={0}; 
 
unsigned u_num; /* 记录无符号数值的中间变量 */
	int i = 0, k;


	
		u_num = (unsigned)num;   /* 其它情况 */
	

	/* 分解整数各个位，注意各位数字的顺序与实际相反 */
	do
	{
		/* 利用字符串字面量实现索引转换 */
		str[i++] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[u_num % (unsigned)10];
		u_num /= 10;
	}
	while(u_num);
	
	str[i] = '\0'; /* 终止字符 */

		printf("%s",str);


}


