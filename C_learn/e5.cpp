#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
class Vect{
	vector<int> V;
	
	public:
	Vect (int n)
	{
		int i=0;
		for(i=0;i<n;i++)
		{
			V.push_back(0);
		}
	 }
	 
	 Vect (int *a,int n)
	 {
	 	int i=0;
	 	for(i=0;i<n;i++)
	 	{
	 	 V.push_back(a[i]);	
		 }
	  }
	  
	  
	  Vect (const Vect &v1) {
	  	int i=0;
	  	int n=(v1.V).size();
	  	for(i=0;i<n;i++)
	  	{
	  		V.push_back((v1.V)[i]);
		  }
	  }
	  void show()
	  {
	  	int i=0;
	  	for(i=0;i<V.size()-1;i++)
	  	{
	  		cout<<V[i]<<" ";
		  }
		  cout<<V[i]<<endl;
	  }
	  
	  void change(int x,int y)
	  {
	  	if(x>=0 && x<V.size())
	  	{
		  
		  V[x]=y;
	    }
	    else 
	    {
	    	cout<<"out of boundary\n";
		}
	  }
};

int main()
{
	int a[]={1,2,3,4,5};
	Vect v1(a,5);
	int nuv2=0;
	int x=0,y=0;
	cin>>nuv2>>x>>y;
	Vect v2(nuv2);
	v1.show();
	v2.show();
	v1.change(x,y);
	Vect v3(v1);
	v1.show();
	v3.show();
	
	return 0;
}
	
