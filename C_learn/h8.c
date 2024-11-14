#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int  zys(int n)
{
        int i=0,j=0,sum=1,a[1000]={0};
        for(i=2;i<n;i++)
        {
                if(n%i==0)
                {
                        a[j++]=i;
                }
        }
        for(i=0;a[i]!=0;i++)
        {
                sum+=a[i];
        }

                return sum;

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
        /*i为质数，0为合数*/ 
}



int main()
{
       int i=0,j=0,l=0,h=0;
       int m=0,n=0,biao=0;
       int *s=calloc(2048,4);
       int *b=calloc(2048,4);
       scanf("%d%d",&l,&h);
       for(i=0;l+i<=h;i++)
       {
       	if(J(l+i)==0)
       	{
		   
        b[j++]=l+i;
    	}
       }

           for(i=0;i<=j;i++)
           {
                s[i]=zys(b[i]);
           }
           for(i=0;i<h-l;i++)
           {
           	if(s[i]<=h && zys(s[i])==b[i]&& s[i]!=b[i])
           	{
           			biao=1;
           			if(s[i]>b[i])
           			{
           				m=s[i];
           				n=b[i];
					   }
					   else
					   {
					   	m=b[i];
					   	n=s[i];
					   }
					   for(j=i+1;j<h-l;j++)
					   {
					   	if(s[j]==b[i])
					   	{
					   		s[j]=-1;
						   }
					   }
					   printf("%d %d\n",n,m);
				   
           		
			   }
		   }
		   if(biao !=1)
		   {
		   	printf("None");
		   }
		   free(s);
		   free(b);
          
 return 0;          
}
