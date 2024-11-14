#include <stdio.h>
int n;
int equa(int* b, int k, int m, int min, int max,int *);
int main()
{
	    int b[100];
	    int i, j,l=0, max = 0,sum=0,p;
	    int a[100]={0};
	      printf("请输入每个小朋友捡到的苹果数，输入-1结束：\n");
			    for(l=0;;l++)
			        {
					scanf("%d",&a[l]);
					if(a[l]==-1) break;

				}
			         a[l]=0;
    for(n=0;a[n]>0;n++)	
	{
		1;
	}
	n = n+1;        //n表示数组a中有效的数值个数
	for (i = 1; i < n; i++)
	{
	       max += a[i];
	}
			    b[0] = 0;
	 for(p=0;p<=n;p++)
	 {
		 sum = sum +a[p];		
	 }
						        
	 if (equa(b, 1, 1, a[0], max,a) > 0)
								       
		 printf("Yes\n%d\n",sum/2);
							   
	 else						           
		 printf("NO\n");
	 return 0;
}  //equa(b,       1,      1,    a[0],   max,     a) 
int equa(int* b, int k, int m, int min, int max,int *A)
{
	   int x;
	   int *a;
	    a=A;
	 if (m > n)

     return -1;

	 if (min >= max)
   {
	  if (min == max)
	 {		  
	  return k;							            							       
     }
      else 
      return -1;
   }
	 b[k] = m;
	 if ((x = equa(b, k + 1, m + 1, min + a[m], max - a[m],a)) > 0)
     return x;
	if ((x = equa(b, k, m + 1, min, max,a)) > 0)
    return x;
    
	 return -1;
}

