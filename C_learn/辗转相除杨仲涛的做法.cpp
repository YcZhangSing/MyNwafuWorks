#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n, t,a, b,benm;
    scanf("%d%d",&m,&n);
    a=m;
    b=n;

          while(n!=0)
    {
        t=m%n;
        m=n;
        n=t;

        }
    benm=a*b/m;
         printf("%d\n%d",m,benm);
         return 0;
}
