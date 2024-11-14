#include<iostream>
using namespace std;
const double pi=3.1415926;
class Cylinder{
	double height;
	double radius;
	
	public:
		Cylinder(double h,double r) : height(0),radius(0)
		{
			height=h;
			radius=r;
		}
		
		double GetRadius()
		{
			return radius;
		}
		double GetHeight()
		{
			return height;
		}
		double Volume()
		{
			return pi*radius*radius*height;
		}
		double Area()
		{
			return (2*pi*radius*radius)+(height*2*pi*radius);
		}
};
int main()
{
	double h=0,r=0;
	cin>>h>>r;
	Cylinder c(h,r);
	double a=c.Volume(),b=c.Area();
	int h0=(int)h;
	int r0=(int)r;
	cout<<"pi=3.14159, height="<<h<<", radius="<<r<<":volume="<<a<<", area="<<b;
	return 0;
}

