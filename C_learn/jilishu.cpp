#include <stdio.h>

int JLS(int a,int b);

int main()
{
	int a,b;
	
	printf("请输入计算区间：");
	
	scanf("%d%d",&a,&b);
	
	JLS(a,b);
	 
	
	
	return 0; 
}
	int JLS(int a,int b)
{
        int i=0,t;
        
        for(t = a;t <= b;t++)
        {
                if(((t%10)) == 8) i++;
                else if(((t/10)%10) == 8) i++;
                else if(((t/100)%10) == 8) i++;
                else if(((t/1000)%10) == 8) i++;
                else if(((t/10000)%10) == 8) i++;

        }
          printf("%d\n",i);
       
        
}

