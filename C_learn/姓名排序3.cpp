#include<stdio.h>
#include<string.h>
int main()
{
	
	int i,j,k;
	char name[10][80],t[80];
	
	for(i=0;i<10;i++) gets(name[i]);
	for(i=0;i<9;i++)
	{
		k=i;
		for(j=i+1;j<10;j++)
		{
		
			if(strcmp(name[k],name[j])>0) k=j;
			if(k!=i)
			{
				strcpy(t,name[i]);
				strcpy(name[i],name[k]);
				strcpy(name[k],t);
			}
		}
			for(i=0;i<10;i++)
			puts(name[i]);
			return 0;
	}
}
