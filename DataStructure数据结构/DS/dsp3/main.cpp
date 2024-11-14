#include<iostream>
#include<string>
using namespace std;
struct Data
{
    string name;
    string snu;
    string sex;
    string age;
    string gc;
    string h;
    void set(string nn,string ss,string se, string a,string g,string hh)
    {
        name=nn;
        snu=ss;
        sex=se;
        age=a;
        gc=g;
        h=hh;
    }

};
class linknode
{
public:
    Data d;
    linknode* link;
};
class linklist
{
private:
    linknode* first;
    linknode* end;
public:
    linklist(int n)
    {
        int i;
        string nn,ss,se,a,g,hh;
        first=new linknode();
        linknode *p=first;

        for(i=0;i<n;++i)
        {
            cin>>nn>>ss>>se>>a>>g>>hh;
            p->link=new linknode();
            p=p->link;
            p->d.set(nn,ss,se,a,g,hh);

        }
        end=p;
        p->link=first;
    }
    void D(linknode* de)
    {
        linknode* pre=first;
        while(pre->link!=de)
        {
            pre=pre->link;
        }
        pre->link=de->link;
        cout<<de->d.name<<' '<<de->d.snu<<' '<<de->d.sex<<' '<<de->d.age<<' '<<de->d.gc<<' '<<de->d.h<<endl;
        delete de;

    }
    void ysf(int m)
    {
        if(m<0)
        {
            return;
        }
        int i=0;
        linknode* p=first;
        linknode* de=p;
        while(1)
        {
            for(i=0;i<m;++i)
            {
                p=p->link;
                if(p==first)
                {
                    p=p->link;
                }
            }
            de=p;
            D(de);
            if(first->link==first)
            {
                break;
            }
        }

    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    linklist l(n);
    l.ysf(m);
    return 0;
}
