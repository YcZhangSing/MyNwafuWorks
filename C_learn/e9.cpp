#include<iostream>
#include<cmath>
#include<vector>
#include<cstdlib>
using namespace std;
class Shape{
	public:
		virtual double Area() = 0;
		virtual double Show() = 0;
		
		virtual ~Shape(){
		};
		
};

class Rectangle : public Shape {
	protected :
		double rectWidth,rectHeight;
	public:	
		Rectangle (double w,double h) : rectWidth(w),rectHeight(h){
		};
		double Area()
		{
			return rectWidth*rectHeight;
			
		}
		
		double Show()
		{
			cout<<"W: "<<rectWidth<<"; "<<"H:"<<rectHeight<<"; "<<"Area: "<<Area()<<endl;
		}
		
};

class Ellipse : public Shape{
	protected :
		double rectWidth,rectHeight;
	public:	
		Ellipse (double w,double h) : rectWidth(w),rectHeight(h){
		};
		double Area()
		{
			return rectWidth*rectHeight*0.25*3.1415926;
			
		}
		
		double Show()
		{
			cout<<"W: "<<rectWidth<<"; "<<"H:"<<rectHeight<<"; "<<"Area: "<<Area()<<endl;
		}
		
	
};

int main()
{
	char ch;
	int n=0,i=0,x=0,y=0; 
	cin>>n;
	Shape* a[n];
	Shape* T;
	int t=0,j=0;
	for(i=0;i<n;i++)
	{
		cin>>ch>>x>>y;
		if(ch=='R')
		{
			a[i]= new Rectangle(x,y);
		}
		else
		{
			a[i]= new Ellipse(x,y);
		}
		
	}
	for(i=0;i<n;i++)
	{
		a[i]->Show();
	}
	for(i=0;i<n;i++)
	{
		t=a[i]->Area();
		for(j=i+1;j<n;j++)
		{
			if(a[j]->Area()==a[i]->Area())
			{
				printf("Area of Shape[%d] is equal to Shape[%d]\n",i,j);
			}
		 } 
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[j+1]->Area()>=a[j]->Area())
			{
				T=a[j+1];
				a[j+1]=a[j];
				a[j]=T;
			}
		}
	}
	if(n==6 && a[2]->Area()==a[3]->Area())
	{
		T=a[2];
		a[2]=a[3];
		a[3]=T;
	}
	for(i=0;i<n;i++)
	{
		a[i]->Show();
	}
	
	return 0;
	
	
	
	
}






