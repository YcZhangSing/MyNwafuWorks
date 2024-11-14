#include<bits/stdc++.h>
using namespace std;
class Person{
	protected:
		
		string szName;
		
		public:
			
			virtual void print()
			{
				cout<<"Person "<<szName<<endl;
			}
			
			Person(string s): szName(s){
			}
			
			string getname()
			{
				return szName;
			}
			
			void setname(string s)
			{
				szName=s;
			}
			virtual void set(string s1,string s2,int n)
			{
				szName=s1;
			}
			
			Person()= default;
			
			
};
class Student :public Person{
	protected:
		string name;
		int iNumber;
		
	public:
			Student()
			{
			}
			Student (int n,string s)
			{
				name=s;
			
				iNumber=n;
			}
			
			virtual void print()
			{
				cout<<"Student "<<szName<<" "<<iNumber<<endl;
			}
			
			virtual void set(string s1,string s2,int n)
			{
				szName=s1;
				iNumber=n;
			}
};
class Teacher :public Person{
	protected:
		int iYear;
		string name;
		
	public:
			Teacher()
			{
			}
			Teacher (string s,int n)
			{
				setname(s);
			
				iYear=n;
			}
			
			virtual void print()
			{
				cout<<"Teacher "<<name<<" "<<iYear<<endl;
			}
			virtual void set(string s1,string s2,int n)
			{
				szName = s1;
				iYear = n;
				
			}
};
class Graduate :public Person{
	protected:
		
		string szResearch;
		int granum;
	public:
			Graduate()
			{
			}
			Graduate (string s1,string s2)
			{
				setname(s1);
			
				szResearch=s2;
			}
			
			void print()
			{
				cout<<"Graduate "<<szName<<" "<<granum<<" "<<szResearch<<endl;
			}
			
			
			
			void set(string s1,string s2,int n)
			{
				szName = s1;
				szResearch = s2;
				granum=n;
			}
};

int main()
{
	int m=0;
	
	cin>>m;
	
	Person* *p=  new Person* [m];
	
	int i=0,j=0;
	string s,t,r;
	for(i=0;i<m;++i)
	{
		cin>>s;
		
		if(s=="Person")
		{
			p[i]= new Person;
			cin>>t;
			p[i]->setname(t);
		}
		
		else if(s=="Student")
		{
			p[i]= new Student;
			cin>>t>>j;
			
		    p[i]-> set(t,r,j); 
		}
		
		else if(s=="Graduate")
		{
			p[i] = new Graduate;
			cin>>t>>j>>r;
			p[i]->set(t,r,j); 
		}
		else if(s=="Teacher")
		{
			p[i]= new Teacher;
			cin>>t>>j;
			p[i]->set(t,r,j); 
		}
	}
	int x=0;
	
	while(scanf("%d",&x)==1)
	{
		p[x]->print();
	}
	
	return 0;
}





