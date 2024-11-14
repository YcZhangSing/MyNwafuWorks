#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
class linknode
{
public:
    int data;
    linknode* link;

    linknode(int x=0)
    {
        data=x;
        link=NULL;
    }
};



class mylist:public linknode{

private:
    linknode* first;
public:
    mylist()
    {
        first = new linknode;
    }
    mylist(int n)
    {
        int i=0,x=0;
        linknode * p=first;
        for(i=0;i<n;++i)
        {

            cin>>x;
            p->link = new linknode;
            p=p->link;
            p->data=x;
        }

    }

    bool myinsert(int x,int i)
    {
        int j=0;
        linknode * p =first;
        for(;j<i;++j)
        {
            p=p->link;
            if(p==NULL)
            {
                return false;
            }
        }
        linknode * newnode=new linknode(x);
        newnode->link=p->link;
        p->link=newnode;

        return true;
    }

    bool mydelete(int x)
    {
        int j=0;
        linknode*p=first;
        for(;j<x;++j)
        {
            p=p->link;
            if(p==NULL)
            {
                return false;
            }
        }
        linknode *dnode=p->link;

        p->link=dnode->link;

        delete dnode;
    }

    void travel()
    {
        linknode* p=first;
        p=p->link;//因为设置了表头节点;
       while(p!=NULL)
       {
           cout<<p->data<<" ";
           p=p->link;
       }
       cout<<endl;
    }

    int getl()
    {
        linknode*p=first->link;
        int c=0;
        while(p!=NULL)
        {
            p=p->link;
            c++;
        }
        return c;
    }
};

int main()
{
    mylist  a(3);
    a.travel();
    cout<<a.getl();
    cout<<endl;
    a.myinsert(100,2);
    a.travel();
    a.mydelete(2);
    a.travel();

}
