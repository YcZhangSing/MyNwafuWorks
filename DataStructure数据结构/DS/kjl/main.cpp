#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct stu
{
	string name;
    long long nu,rank;
    double g1,g2,g3,aver;
};
bool com(stu a,stu b)
{
    return a.aver < b.aver;
}
class linknode
{
public:
    stu s;

    linknode* link=NULL;
};

class linklist
{
    private:
    linknode * first;
    public:
    linklist(int n)
    {
        first=new linknode();
        string sn;
        long long nnu;
        double gg1,gg2,gg3;
        linknode *p= first;
        for(int j=0;j<n;++j)
        {
            cin>>nnu>>sn>>gg1>>gg2>>gg3;
            p->link=new linknode();
            p=p->link;
            p->s.g1=gg1;
            p->s.g2=gg2;
            p->s.g3=gg3;
            p->s.name=sn;
            p->s.nu=nnu;
            p->s.aver=((gg1+gg2+gg3)/3.);
        }
    }
     int lenth()
{
    linknode* p=first;
    int l=0;
    while(p!=NULL)
    {
		p=p->link;
		l++;
	}
	return l-1;
}
    void msort()
    {
        int len=lenth();
        stu copy[len];
        int i=0;
        linknode* p=first;
        for(i=0;i<len;++i)
        {
            p=p->link;
            copy[i]=p->s;
        }
        sort(copy, copy+len,com);
        p=first;
        for(i=0;i<len;++i)
        {
            p=p->link;
            p->s=copy[i];
        }
    }

    void show()
    {
        linknode* p=first->link;
        long long r=1;
        while(p!=NULL)
        {
            printf("%lld "  ,p->s.nu);
      		printf("%s "  ,p->s.name.c_str());
       		printf("%.2f "  ,p->s.g1);
       		printf("%.2f "  ,p->s.g2);
       		printf("%.2f "  ,p->s.g3);
       		printf("%.2f "  ,p->s.aver);
       		printf("%lld\n",r);
			p=p->link;
			r++;
        }
    }


};
int main()
{
    int x;
    cin>>x;
    linklist l(x);


    l.show();
}
