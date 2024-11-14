
int sum(int(*f)(int), int start, int end) 
{
	int i;
	int sum=0;
	if(f==NULL)
	{
		return 0;
	}
	
	else if(start<end)
	{
		for(i=start;i<=end;i++)
		{
			sum+=f(i);
		}
		return sum;
	}
	
	else
	{
		for(i=end;i<=start;i++)
		{
			sum+=f(i);
		}
		return sum;
	}
}
	

