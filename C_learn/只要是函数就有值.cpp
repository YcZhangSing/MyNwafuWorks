#include<stdio.h>
int main()
{
	int n;
	n=printf("ab'1'\l803\n");//函数printf也是有值的，它的值就是双引号里的字符个数 
	printf("%d\n",n);//程序输出n时n=10，注意字符数的算法 
	printf("%%");
	/*输出百分号%要在编写代码时编写%%  */ 
	return 0;
 } 
