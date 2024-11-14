#include <stdio.h>
int jls(int,int);

int main()
{
        int a,b;
        scanf("%d %d",&a,&b);
        jls(a,b);
        return 0;
}
int jls(int a,int b)
{
        int i=0;
        for(a;a<=b;a++)
        {if((a-8)%10 == 0) i=i+1;
                else {do
                        {a =a/10;
                        a = (int)a;
                        if ((a-8)%10 == 0) i = i+1;
                        else i = i;}
                        while (a<10);
                }
        }
        printf("%d",i);
}

