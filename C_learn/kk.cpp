#include <stdio.h>
int main()
{
int i,n,m,jh=0,oh=0,jg=0,og=0;
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&m);
if(m%2!=0)
{
jh=jh+m;
jg++;
}
else
{
oh=oh+m;
og++;
}
}
printf("%d\n%d\n%d\n%d\n",jh,jg,oh,og);
} 
