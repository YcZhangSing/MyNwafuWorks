#include<stdio.h>
int jnu(char c)
{
        if(c=='.'|| (c>='0'&& c<='9'))
        {
                return 1;
        }
        else
        {
                return 0;
        }
}
int pnu(int n,char *a)
{
        int i=0;
        for(i=0;jnu(a[n+i])==1;i++);
        int j=n;
        for(;j<n+i;j++)
        {
                printf("%c",a[j]);
                if(j==n+i-1)
                {
                        printf("\n");
                }
        }
        return n+i;
}

int main()
{
        char a[40]={0};
        scanf("%s",a);
        int i=0;
        while(a[i]!='\0')
        {
                 if(jnu(a[i]))
                 {
                         i=pnu(i,a);
                 }
                 else if(a[i]=='(' || a[i]==')' || a[i]=='+' || a[i]=='*' || a[i]=='/')
                 {
                         printf("%c\n",a[i++]);
                 }
                 else if(a[i]=='-')
                 {
                         if(jnu(a[i+1]) && a[i-1]=='(')
                         {
                                 printf("-");
                                 i++;
                         }
                         else
                         {
                         	printf("-\n");
                         	i++;
						 }
                 }
        }
}

