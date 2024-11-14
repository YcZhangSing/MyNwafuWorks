#include <stdio.h>
int JLs(int,int);

int main(){
	printf("请输入计算区间：")；
	
	JLS(int,int);
	
	return 0; 
}
int JLS(int,int)
{
        int i=0,a,b,t;
        scanf("%d%d",&a,&b);
        for(t = a;t <= b;i++)
        {
                if(((t%10)) == 8) i++;
                else if(((t/10)%10) == 8) i++;
                else if(((t/100)%10) == 8) i++;
                else if(((t/1000)%10) == 8) i++;
                else if(((a/10000)%10) == 8) i++;

        }
        printf("%d\n",i);
        
}

