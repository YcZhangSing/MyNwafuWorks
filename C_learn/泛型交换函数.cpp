#include<stdio.h>
#include<stdlib.h> 
void Swap(void *vp1,void *vp2,int size)//定义两个交换数据的void类型的指针，size是你想要交换数据类型的字节数。
{
 
	char  *tmp = (char *)malloc(size);//动态的创建一个char类型size字节大小的指针
	char *p1 = (char *)vp1;//把形参强转为char*
	char *p2 = (char *)vp2;//把形参强转为char*
	int i;
	for(i=0;i<size;i++)//把指针p1中的数据一个一个字节的传到tmp中
	{
		tmp[i] = p1[i];
	}
 
	for(i=0;i<size;i++)//把指针p2中的数据一个一个字节的传到p1中
	{
		p1[i] = p2[i];
	}
 
	for(i=0;i<size;i++)//把指针tmp中的数据一个一个字节的传到p2中
	{
		p2[i] = tmp[i];
	}
	free(tmp);//释放动态内存
	
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
