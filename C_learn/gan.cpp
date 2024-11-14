#include<stdio.h>

int main()
{
                int x=1;

                do
                {
                        x=x+1;
                        x++;
                }
                while (x%2==1&&x%3==2&&x%5==4&&x%6==5&&x%7==0);

                printf("%d",x);
                return 0;
}
