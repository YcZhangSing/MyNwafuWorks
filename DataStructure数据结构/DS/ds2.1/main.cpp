#include<iostream>
#include<string.h>
#include<algorithm>
const int LEN=900;
using namespace std;
class mylist
{
private:
    char a[LEN];
public:
    int len;
    mylist()
    {
        len=0;
    }

    bool push(char x)
    {
        if(len>LEN)
        {
            return false;
        }
        a[len++]=x;
        return true;
    }
    char look()
    {
        if(len>0)
        {
            return a[len-1];
        }
        return '#';
    }
    void pop()
    {
       // cout<<a[len-1];
        len--;
    }
    bool ifempty()
    {
        if(len==0)
        {
            return true;
        }
        return false;
    }
};

int main()
{

    mylist l;
    char x;
    while(1)
    {
        cin>>x;
        if(x=='#')
        {
            break;
        }
        if(l.look()==x)
        {
            l.pop();
            continue;
        }
        l.push(x);
    }
    if(l.ifempty())
    {
        cout<<"Æ¥Åä"<<endl;
    }
    else
    {

        cout<<"²»Æ¥Åä"<<endl;

    }

    return 0;

}
