#include<stdio.h>
int f(unsigned int n)
{
		if(n<=3){
			return 1;
		}
		else if(n==4){
		return 2;
		}
		else {
			return (f(n-1)+f(n-1)-f(n-3));
		}
 } 
 int main()
 {
 	double m;
	unsigned int n;
 	scanf("%lf",&m);
 	n = (unsigned int)m+1;
 	printf("%d\n",f(n));
 	return 0;
 }
 //

题目1：病毒是世界上最小的，也是最简单的微生物。它们的大小约在28纳米～200纳米（1纳米是1毫米的百万分之一）。病毒只能在其他生物的活细胞内繁殖、生长、代谢。假定在培养皿中有一种病毒，从第三个小时开始每小时都会分裂出一个病毒，新的病毒从第3个小时开始又每小时分裂一个病毒。按此规律，在第n个小时后，培养皿中共有多少个病毒？

    输入：经过的小时数（非负整数）
    输出：在经过指定的时间后，培养皿中的病毒个数
    输入样例：20
    输出样例：6765


 	
