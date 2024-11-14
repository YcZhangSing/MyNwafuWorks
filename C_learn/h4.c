#include <stdio.h>
int length=0; 
int cnt=0;
int division(int sub,int length);
int N=0;
int num[30]={0};
  
int main() 
{
scanf("%d",&N);
int sub=N;
division(sub,0); 
    return 0;
}
int division(int sub,int length)
{
 if(sub==0)
 {
 
  cnt++;
  printf("%d=%d",N,num[0]); 
  if(length>1)
  {
   int j=1;
   for(;j<=length-1;j++)
   {
    printf("+%d",num[j]);  
   } 
   
   if(cnt%4!=0)
   {
    printf(";"); 
   }
   if(cnt%4==0)
   {
    printf("\n"); 
    } 
  }
  if(length==1)
  printf("\n"); 
  
 }
 int i=1;
 for(;i<=sub;i++)
 {
  if(length==0||(length!=0&&num[length-1]<=i))
  {   
   num[length]=i;
   length++; 
   sub=sub-i;
   division(sub,length);
   length--;
   sub=sub+i;
   num[length]=0; 
   
  } 
 } 
}
