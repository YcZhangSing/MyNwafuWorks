#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
	BIN = 2,
	OCT = 8,
	DEC = 10,
	HEX = 16,
}radix;

/* 整数转字符串 */
char *i2a(int, char *, int);
char *i2a_spf(int, char *, int);
/* 字符串转整数 */
int a2i(const char *);
int a2i_scf(const char *);

/* 判断一个字符是不是空白 */
int isspace(int);
/* 判断一个字符是不是数字 */
int isdigit(int);

/* 字符串逆序 */
char* strrev(char*, int, int);

/* qsort需要的比较函数 */
int cmp(const void *, const void *);


/* 测试函数 */
int main(void)
{
	int number = -12345;
	char string[32] = {0};
	int len = 0;

	printf("test i2a:\n");
	i2a(number, string, BIN);
	printf("integer = %d, bin string = %s\n", number, string);
	i2a(number, string, OCT);
	printf("integer = %d, oct string = %s\n", number, string);
	i2a(number, string, DEC);
	printf("integer = %d, dec string = %s\n", number, string);
	i2a(number, string, HEX);
	printf("integer = %d, hex string = %s\n", number, string);

	printf("test i2a_spf:\n");
	i2a_spf(number, string, OCT);
	printf("integer = %d, oct string = %s\n", number, string);
	i2a_spf(number, string, DEC);
	printf("integer = %d, dec string = %s\n", number, string);
	i2a_spf(number, string, HEX);
	printf("integer = %d, hex string = %s\n", number, string);

	strcpy(string, "-12345");

	printf("test a2i:\n");
	number = a2i(string);
	printf("string = %s, integer = %d\n", string, number);

	printf("test a2i_scf:\n");
	number = a2i_scf(string);
	printf("string = %s, integer = %d\n", string, number);

	number = 32015;
	i2a(number, string, DEC);
	len = strlen(string);
	qsort(string, len, sizeof(string[0]), cmp);
	number = a2i_scf(string);
	printf("string = %s, integer = %d\n", string, number);

	return 0;
}

/* i2a函数定义 */
/* 采用与基数radix(进制)求余数并不断相除的方法进行转换 */
char *i2a(int num, char *str, int radix)
{
	unsigned u_num; /* 记录无符号数值的中间变量 */
	int i = 0, k;

	/* 确定u_num的值 */
	if(radix == DEC && num < 0) /* 十进制负数 */
	{
		u_num = (unsigned) - num;
		str[i++] = '-';
	}
	else
	{
		u_num = (unsigned)num;   /* 其它情况 */
	}

	/* 分解整数各个位，注意各位数字的顺序与实际相反 */
	do
	{
		/* 利用字符串字面量实现索引转换 */
		str[i++] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[u_num % (unsigned)radix];
		u_num /= radix;
	}while(u_num);
	str[i] = '\0'; /* 终止字符 */

	/* 逆序起始位置(正负号) */
	if(str[0] == '-')
	{
		k = 1;   /* 十进制负数 */
	}
	else
	{
		k = 0;
	}

	strrev(str, k, i - 1);

	return str;
}

/* i2a_spf函数定义 */
/* 使用sprintf函数实现转换 */
/* sprintf函数只支持8、10、16进制转换 */
char *i2a_spf(int num, char *str, int radix)
{
	switch(radix)
	{
		case OCT:
			sprintf(str, "%o", (unsigned)num); /* 转为8进制表示的字符串 */
			break;
		case DEC:
			sprintf(str, "%d", num); /* 转为10进制表示的字符串 */
			break;
		case HEX:
			sprintf(str, "%X", (unsigned)num); /* 转为16进制表示的字符串 */
			break;
		default:
			return NULL;
	}
	return str;
}

/* a2i函数定义 */
/* 通过与权值相乘累加的方法进行转换 */
int a2i(const char *nptr)
{
	int c;
	int total;
	int sign;

	/* 跳过开始的空白(注意类型转换) */
	while(isspace((int)(unsigned char)*nptr) )
	{
		++nptr;
	}

	/* 处理正负号 */
	c = (int)(unsigned char) * nptr++;
	sign = c;
	if(c == '-' || c == '+')
	{
		c = (int)(unsigned char) * nptr++;
	}

	/* 通过权值相乘累加实现转换 */
	total = 0;
	while(isdigit(c)) /* 是数字 */
	{
		/* total = 10 * total + (c - '0'); */ /* 将字符转成数字后累加 */
		/* total = total * 23 + total * 21 = total * 8 + total * 2 = total * 10 */
		total = (total << 3) + (total << 1) + (c - '0');
		c = (int)(unsigned char) * nptr++; /* 取下一个数字 */
	}

	/* 处理负数 */
	if (sign == '-')
	{
		return -total;
	}
	else
	{
		return total;
	}
}

/* a2i_scf函数定义 */
/* 使用sscanf()函数实现转换 */
int a2i_scf(const char *nptr)
{
	int t;
	if(sscanf(nptr, "%d", &t) == 1)
	{
		return t;
	}
	else
	{
		return EOF;
	}
}

/* 判断一个字符是不是空白 */
/* 参数使用int型以与getchar()返回类型匹配 */
int isspace(int x)
{
	if(x == ' ' || x == '\t' || x == '\n' || x == '\f' || x == '\b' || x == '\r')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/* 判断一个字符是不是数字 */
/* 参数使用int型以与getchar()返回类型匹配 */
int isdigit(int x)
{
	if(x <= '9' && x >= '0')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/* 利用循环实现字符串指定范围内的逆序操作 */
char* strrev(char* s, int left, int right)
{
	char t;
	while(left < right)
	{
		t = s[left];
		s[left++] = s[right];
		s[right--] = t;
	}

	return s;
}

int cmp(const void *p, const void *q)
{
	return (*(char*)p - *(char*)q);
}

