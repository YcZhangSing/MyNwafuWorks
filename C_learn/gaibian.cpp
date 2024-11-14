#include <stdio.h>
int n=0;
int equa(int* b, int k, int m, int min, int max,int *);
int main()
{
    int b[29];
    int i,sum=0,j,l=0, max = 0,u=0;
    int a[3]={0};
    printf("请输入每个小朋友捡到的苹果数，输入-1结束：\n");
    
    for(l=0;;l++)
    {
		scanf("%d",&a[l]);
		if(a[l]==-1) break;
	}
	a[l]=0;
	
	for(l=0;;l++)
	{
		sum = sum+a[l];
	}
	
	for(u=0;a[u]>0;u++) n++;
	
   for (i = 1; i < n; i++)
    {
        max += a[i];
    }
    b[0] = 0;
    sum = sum/2;
    if (equa(b, 1, 1, a[0], max,a) > 0)
        printf("Yes\n%d\n",sum);
    else
        printf("NO\n");
    return 0;
}
int equa(int* b, int k, int m, int min, int max,int *A)
{
    int x;
    int *a;
    a=A;
    if (m > n)return -1;
    if (min >= max)
    {
        if (min == max)
        {
            return k;
        }
        else return -1;
    }
    b[k] = m;
    if ((x = equa(b, k + 1, m + 1, min + a[m], max - a[m],a)) > 0)return x;
    if ((x = equa(b, k, m + 1, min, max,a)) > 0)return x;
    return -1;
}
