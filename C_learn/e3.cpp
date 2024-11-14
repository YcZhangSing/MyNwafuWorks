#include<iostream>
#include<cmath>
using namespace std;
void d(double *a,double x1,double y1,double z1,double x2=0,double y2=0,double z2=0)
{
	a[0]=sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));
	a[1]=sqrt(x1*x1 + y1*y1 + z1*z1);
}
	int main()
	{
		double a[2]={0},b[6]={0};
		
		int i=0;
		for(i=0;b[i]!=EOF;++i)
		{
			cin>>b[i];
		}
		if(i==5)
		{
			d(a,b[0],b[1],b[2],b[3],b[4],b[5]);
		}
		else
		{
			d(a,b[0],b[1],b[2]);
		}
		cout<<a[0]<<a[1];
		return 0;
		
	}
	
	
