#include<stdio.h>
int main()
{
        char a[500]={0},ch;
        int i=0,t=0,lj=0,rj=0;
        while((ch=getchar())!=EOF)
        {
        if(i<500)
        {
                a[i++]=ch;
        }
        t=i;
        }
        for(i=0;i<t;i++)
        {
                if(a[i]=='{') lj++;
                else if(a[i]=='}') rj++;
        }

        if(rj==rj) printf("Yes\n");
        else if(rj>lj) printf("No(-1)\n");
        else printf("No(%d)\n",lj-rj);
        return 0;
}

