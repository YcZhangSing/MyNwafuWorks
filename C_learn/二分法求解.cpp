#include<stdio.h>
int main()
{

 double n,t,b,a=0;
		scanf("%lf",&n);
		b = n;
	//	if(n==4) t=2;
	//	else if(n==0) t=0;
	//	else
    {

       while ((b-a)>(0.00000001))
        {
        	t = (a+b)/2;
                if(((a*a)-n)*((t*t)-n)<0) b = t;
                
                else a = t;
        }
    }

		printf("%.3lf",t);
		return 0;
	}
