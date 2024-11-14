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

/* ����ת�ַ��� */
char *i2a(int, char *, int);
char *i2a_spf(int, char *, int);
/* �ַ���ת���� */
int a2i(const char *);
int a2i_scf(const char *);

/* �ж�һ���ַ��ǲ��ǿհ� */
int isspace(int);
/* �ж�һ���ַ��ǲ������� */
int isdigit(int);

/* �ַ������� */
char* strrev(char*, int, int);

/* qsort��Ҫ�ıȽϺ��� */
int cmp(const void *, const void *);


/* ���Ժ��� */
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

/* i2a�������� */
/* ���������radix(����)����������������ķ�������ת�� */
char *i2a(int num, char *str, int radix)
{
	unsigned u_num; /* ��¼�޷�����ֵ���м���� */
	int i = 0, k;

	/* ȷ��u_num��ֵ */
	if(radix == DEC && num < 0) /* ʮ���Ƹ��� */
	{
		u_num = (unsigned) - num;
		str[i++] = '-';
	}
	else
	{
		u_num = (unsigned)num;   /* ������� */
	}

	/* �ֽ���������λ��ע���λ���ֵ�˳����ʵ���෴ */
	do
	{
		/* �����ַ���������ʵ������ת�� */
		str[i++] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[u_num % (unsigned)radix];
		u_num /= radix;
	}while(u_num);
	str[i] = '\0'; /* ��ֹ�ַ� */

	/* ������ʼλ��(������) */
	if(str[0] == '-')
	{
		k = 1;   /* ʮ���Ƹ��� */
	}
	else
	{
		k = 0;
	}

	strrev(str, k, i - 1);

	return str;
}

/* i2a_spf�������� */
/* ʹ��sprintf����ʵ��ת�� */
/* sprintf����ֻ֧��8��10��16����ת�� */
char *i2a_spf(int num, char *str, int radix)
{
	switch(radix)
	{
		case OCT:
			sprintf(str, "%o", (unsigned)num); /* תΪ8���Ʊ�ʾ���ַ��� */
			break;
		case DEC:
			sprintf(str, "%d", num); /* תΪ10���Ʊ�ʾ���ַ��� */
			break;
		case HEX:
			sprintf(str, "%X", (unsigned)num); /* תΪ16���Ʊ�ʾ���ַ��� */
			break;
		default:
			return NULL;
	}
	return str;
}

/* a2i�������� */
/* ͨ����Ȩֵ����ۼӵķ�������ת�� */
int a2i(const char *nptr)
{
	int c;
	int total;
	int sign;

	/* ������ʼ�Ŀհ�(ע������ת��) */
	while(isspace((int)(unsigned char)*nptr) )
	{
		++nptr;
	}

	/* ���������� */
	c = (int)(unsigned char) * nptr++;
	sign = c;
	if(c == '-' || c == '+')
	{
		c = (int)(unsigned char) * nptr++;
	}

	/* ͨ��Ȩֵ����ۼ�ʵ��ת�� */
	total = 0;
	while(isdigit(c)) /* ������ */
	{
		/* total = 10 * total + (c - '0'); */ /* ���ַ�ת�����ֺ��ۼ� */
		/* total = total * 23 + total * 21 = total * 8 + total * 2 = total * 10 */
		total = (total << 3) + (total << 1) + (c - '0');
		c = (int)(unsigned char) * nptr++; /* ȡ��һ������ */
	}

	/* ������ */
	if (sign == '-')
	{
		return -total;
	}
	else
	{
		return total;
	}
}

/* a2i_scf�������� */
/* ʹ��sscanf()����ʵ��ת�� */
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

/* �ж�һ���ַ��ǲ��ǿհ� */
/* ����ʹ��int������getchar()��������ƥ�� */
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

/* �ж�һ���ַ��ǲ������� */
/* ����ʹ��int������getchar()��������ƥ�� */
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

/* ����ѭ��ʵ���ַ���ָ����Χ�ڵ�������� */
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

