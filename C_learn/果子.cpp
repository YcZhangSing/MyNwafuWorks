#include<stdio.h>
#define N 1000

void sort(int *, int len);
int judge(int *,int sum, int len);

int main()
{
        int a[N], len=0, i, sum=0;
        for(i=0;;i++){
                scanf("%d", &a[i]);
                if (a[i] == -1)
                        break;
                len++;
                sum+=a[i];
        }
        sort(a,len);
	if(sum%2 != 0)
		printf("No\n");
	else if(judge(a,sum,len))
                printf("Yes\n%d\n", sum/2);
        else printf("No\n");
        return 0;

}


void sort(int a[], int len)
{
        int i, j, temp;
        for(i = len-2 ; i >= 0 ; i--){
                for(j =len-2 ; j >= 0 ; j--){
                        if(a[j] > a[j-1]){
                              temp=a[j];
                              a[j]=a[j-1];
                              a[j-1]=temp;
                              }
                        }
                }
}



int judge(int a[], int sum, int len)
{
	int q=0, b=0;
        if(a[0] > sum/2)
                return 0;
        if(a[0] == sum/2)
                return 1;
        if(b == len-1)
                return 0;
        q += a[b];
        if(q < sum/2){
                b++;
                judge(a, sum, len);
        }
        else if(q > sum/2){
                q -= a[b];
                b++;
                judge(a, sum, len);
        }
        else if(q == sum/2)
                return 1;
}
