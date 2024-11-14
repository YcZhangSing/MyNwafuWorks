#include<stdio.h>
#include<math.h>
int J(int n);
int main()
{
        int i=0, n=0,n0=0,l=0,a[100]={0};;
        scanf("%d%d",&n,&l);
        n0=n;
        for(i=0;i<l;n0--)
        {
                if(J(n0))
                {
                        a[i++]=n0;
                }
                if(n0<2)
                {
                	l=i;
					break;
				}
        }
        int sum=0;
        for(i=0;i<l;i++)
        {
                sum+=a[i];
        }

        for(i=0;a[i+1]!=0;i++)
        {
                printf("%d+",a[i]);
        }

        printf("%d=%d",a[l-1],sum);

        return 0;
}
int J(int n)
{
        int i;
        int b=0;
        int s=sqrt(n);
        if(n==2)
        {
                return 1;
        }
        if(n<2 || n%2==0)
        {
                return 0;
        }


        for(i=3;i<=s;i++)
        {
                if(n%i==0)
                {
                        b=1;
                        break;
                }
        }

        if(b==0) return 1;
        else return 0;
}

