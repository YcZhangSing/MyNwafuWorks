#include<iostream>
#include<cmath>
using namespace std;
class Point
{
	double X,Y;
	
	public:
	Point(double xx,double yy) {X=xx,Y=yy;
	} 
	
	friend class Line;
 }; 
 class Line{
 	Point D;
 	Point E;
 	
 	public:
 		
 	Line(Point A,Point B) : D(A),E(B){
	 }
 	
 	double len()
 	{
 		
 		
 		return (sqrt((D.X-E.X)*(D.X-E.X)+(D.Y-E.Y)*(D.Y-E.Y)));
	 }
	 
	 friend class Triangle;
 	
 };
 class Triangle{
 		Line m;
		Line l;
		Line n;
 		double p,a,b,c;
 	public:
 		Triangle(Line mm,Line ll,Line nn) : m(mm),n(nn),l(ll){
		 }
		 
		 double zc()
		 {
		
		 	
		 	return (m.len()+n.len()+l.len());
		 }
		 
		 double area()
		 {
		 	a=m.len();
			 b=n.len();
			 c=l.len();
			 p=0.5*(a+b+c);
			 
			 return (sqrt(p*(p-a)*(p-b)*(p-c)));
		 	
		 }
		 
		 
		 
		 
 };
 int main()
 {
 	double x1,x2,x3,y1,y2,y3;
 	cin>>x1>>y1>>x2>>y2>>x3>>y3;
 	
 	Point A(x1,y1);
 	Point B(x2,y2);
 	Point C(x3,y3);
 	
 	Line l1(A,B);
 	Line l2(A,C);
 	Line l3(B,C);
 	
 	Triangle tan(l1,l2,l3);
 	
 	cout<<tan.zc()<<" "<<tan.area();
 	return 0;
 	
 }
 

