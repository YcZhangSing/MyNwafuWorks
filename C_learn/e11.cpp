#include<iostream>
#include<cmath>
using namespace std;

class  Rational{

	int iUp;
	int iDown;
	int Gcd(int l,int r)
    {
        int t=l%r;
        while(t!=0)
        {
            l=r; r=t; t=l%r;
        }
        return r;
    }
void Reduce()
    {
        int t=abs(Gcd(iUp,iDown));
        iUp=iUp/t;
        iDown=iDown/t;
        if(iDown<0) { iDown=-iDown; iUp=-iUp; }
    }
    
public:
	Rational(){  
	}
	Rational(int up,int down)
	{
		iUp=up;
		iDown=down;
		Reduce();
	}
	Rational operator-()
	{
		iUp=-iUp;
		return *this;
	}
	Rational operator=(Rational r)
	{
		iUp=r.iUp;
		iDown=r.iDown;
		return *this;
	}
	Rational operator++()
	{
		iUp+=iDown;
		return *this;
	}
	Rational operator++(int)
	{
		iUp+=iDown;
		return *this;
	}
	
	Rational operator--()
	{
		iUp-=iDown;
		return *this;
	}
	Rational operator--(int)
	{
		iUp-=iDown;
		return *this;
	}
	Rational operator+(Rational r)
	{
		int DOWN=iDown*r.iDown;
		int UP=(iUp*r.iDown)+(iDown*r.iUp);
		int gcd=Gcd(DOWN,UP);
		iUp=UP/gcd;
		iDown=DOWN/gcd;
		return *this;
	}
	Rational operator-(Rationala,Rational b)
{
    Rational t;
    t.iUp = a.iUp*b.iDown - b.iUp*a.iDown;
    t.iDown = a.iDown * b.iDown;
    return t;
}
	Rational operator*(Rational r)
	{
		int DOWN=iDown*r.iDown;
		int UP=r.iUp*iUp;
		int gcd=Gcd(DOWN,UP);
		iUp=UP/gcd;
		iDown=DOWN/gcd;
		return *this;
	}
	Rational operator/(Rational r)
	{
		if(r.iUp!=0)
		{ 
		int DOWN=iDown*r.iUp;
		int UP=iUp*r.iDown;
		int gcd=Gcd(DOWN,UP);
		iUp=UP/gcd;
		iDown=DOWN/gcd;
		return *this;
		} 
	}
	Rational operator>(Rational r)
	{
		double a=iUp/iDown;
		double b=r.iUp/r.iDown;
		if(a>b)
		{
			cout<<"true"<<endl;
		}
		else
		{
			cout<<"false"<<endl;
		}
	
		
	}
	Rational operator<(Rational r)
	{
		double a=iUp/iDown;
		double b=r.iUp/r.iDown;
		if(a<b)
		{
			cout<<"true"<<endl;
		}
		else
		{
			cout<<"false"<<endl;
		}
	
		
	}
	Rational operator>=(Rational r)
	{
		double a=iUp/iDown;
		double b=r.iUp/r.iDown;
		if(a>=b)
		{
			cout<<"true"<<endl;
		}
		else
		{
			cout<<"false"<<endl;
		}
	
		
	}
	Rational operator<=(Rational r)
	{
		double a=iUp/iDown;
		double b=r.iUp/r.iDown;
		if(a<=b)
		{
			cout<<"true"<<endl;
		}
		else
		{
			cout<<"false"<<endl;
		}
	
		
	}
	friend ostream& operator<<(ostream &out,const Rational& );
	
	
};
ostream& operator<<(ostream& out,const Rational &a)
{
	if(a.iDown!=1)
	{
		out<<a.iUp<<"/"<<a.iDown;
		
	}
	else
	{
		out<<a.iUp;
	}
	return out;
}


int main()
{

	int a1,a2;
	int b1,b2;
	cin>>a1>>a2>>b1>>b2;
	Rational a(a1,a2);
	Rational b(b1,b2);
    
    Rational c;
    c=a+b;
    cout<<"a+b: "<<c<<endl;
    c=a-b;
    cout<<"a-b: "<<c<<endl;
    c=a*b;
    cout<<"a*b: "<<c<<endl;
    c=a/b;
    cout<<"a/b: "<<c<<endl;
    c=-a;
    cout<<"-a: "<<c<<endl;
    c=++a;
    cout<<"++a: "<<c<<endl;
    c=--a;
    cout<<"--a: "<<c<<endl;
    c=a++;
    cout<<"a++: "<<c<<endl;
    c=a--;
    cout<<"a--: "<<c<<endl;
	return 0;
}
