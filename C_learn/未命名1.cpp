#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double years,sum,money=1.0,rate;
	while(money>0)
	{
	
	cout<<"##############################"<<endl;
	cout<<"���������뱾�𣬴�����޺�����"<<endl;
	cin>>money>>years>>rate;
	 if(money<=0)
	 {
	 	cout<<"error!" <<endl;
		 break;
	 }
	sum=money*(pow(1+rate,years));
	cout<<sum<<endl;
	cout<<"##############################"<<endl;
	cout<<endl;
    }
	return 0;
 } 
