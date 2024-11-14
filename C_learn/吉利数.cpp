#include <stdio.h>
int max(int,int);
int min(int,int);
int jls(int,int);

int main()
{
        int a,b;
        scanf("%d£¬%d",&a,&b);
        a = max(a,b);
        b = min(a,b);
        jls(a,b);
        return 0;
}
int max(int a,int b){
        int max;
        max = (a>b)? a:b;
}

int min(int a,int b){
        int min;
        min = (a<b)? a:b;
}

int jls(int a,int b){
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

