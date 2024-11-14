#include<iostream>
using namespace std;
void Math(float a,float b,float &sum,float &sub,float &pro)
{
	sum=a+b;
	sub=a-b;
	pro=a*b;
}
int main()
{
	float a=0,b=0,sum0,sub0,pro0;
	cin>>a>>b;
	float &sum=sum0;
	float &sub=sub0;
	float &pro=pro0;
	Math(a,b,sum,sub,pro);
	cout<<sum<<" "<<sub<<" "<<pro;
	return 0;
}

