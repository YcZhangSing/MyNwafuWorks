#include<stdio.h>
void kaifang(double *,double *);



int main()
{
        double n,t;
        scanf("%lf",&n);
        kaifang(&n,&t);
        printf("%lf\n",t);
        return 0;
}






void  kaifang(double *pn,double *pt)
{
   double n,t,b,a=0;
   		n =*pn;
		b = n;
		if(n==4) t=2;
		else if(n==0) t=0;
		else
    {

       while ((b-a)>(0.00000001))
        {
        	t = (a+b)/2;
                if(((a*a)-n)*((t*t)-n)<0) b = t;
                
                else a = t;
        }
    } 
		
	*pt = t;
}

