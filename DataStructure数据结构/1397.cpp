#include<iostream>
#include<string.h>
#include<algorithm>
const int LEN=900;
using namespace std;
class mylist
{

private:
    int a[LEN];
    int len;
public:
    mylist(int l=0)
    {
        len=l;
        for(int i=0;i<len;++i)
        {
            int x=0;
            cin>>x;
            a[i]=x;
        }
    }
    void myinsert(int index,int x)
    {
        index--;
        if(index<0  || index>len-1)
        {
            cout<<"越界，插入失败";
            return;
        }

        int i=0;
        for(i=len;i>index;--i)
        {
            a[i]=a[i-1];
        }
        a[index]=x;
        len++;

    }

    void mydelete(int index)
    {
        index--;
        if(index<0  || index>len-1)
        {
            cout<<"越界，插入失败";
            return;
        }
        int i=0;
        for(i=index;i<len;++i)
        {
            a[i]=a[i+1];
        }
        len--;
    }

    int myfind(int x)
    {
        for(int i=0;i<len;++i)
        {
            if(a[i]==x){
               cout<<i+1<<endl;
               return 0;}
        }
        cout<<"Not found"<<endl;
        return -1;
    }

    void travel()
    {

        for(int i=0;i<len;++i)
        {
            cout<<a[i]<<' ';
        }
        cout<<endl;
    }
    void mysort()
    {
        sort(a,a+len);
    }
    void inver()
    {

        for(int i=len-1;i>=0;--i)
        {
            cout<<a[i]<<' ';
        }
        cout<<endl;
    }

    void merg(mylist& b)
    {
        int i=0,j=0;
        for(i=len;i<len+b.getlen();++i)
        {
            a[i]=(b.getdata())[j++];
        }
        len+=b.getlen();
    }

    int* getdata()
    {
        return a;
    }
    int getlen()
    {
        return len;
    }
};
int main()
{
    int n;
    cin>>n;
    mylist a(n);
    int i,x;
    cin>>x>>i;
    a.myinsert(i,x);
    a.travel();
    cin>>i;
    a.mydelete(i);
    a.travel();
    cin>>x;
    a.myfind(x);
    a.inver();
    cin>>n;
    mylist b(n);
    a.merg(b);
    a.mysort();
    a.travel();

    return 0;
}
