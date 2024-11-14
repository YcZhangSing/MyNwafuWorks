#include<stdio.h>

int isprime(int n)
{
	int i;
	for(i=2;i<n;i++)
	{
		if(n%i==0) 
		{   i=0;
		break;
	}
	}
	if(i==n-1) return 1;
	else return 0;
}
