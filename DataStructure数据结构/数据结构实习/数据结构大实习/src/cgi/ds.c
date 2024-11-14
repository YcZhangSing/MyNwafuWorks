#include <string>
#include <math.h>
#include<cstring>
#include<string.h>
#include <fstream>
#include<iostream>
#include<assert.h>
using namespace std;
const int CONT = 4;
const int VALUE = 24;
void Search(int n,int*,string *,bool*,int*);
int number[4096];
string biaodashi[4096];
bool Panduan = false;
int mcount = 0;
enum { STACK_INIT_SIZE = 10, STACK_INC_SIZE = 2 };//给定初始容量为10，且按照2倍的增量来扩容

class MyStack
{

private:
    int* _data; //从堆区获取空间，如果定义成数组，没有办法扩容
    int _capc;  //容量
    int _top;   //栈顶
public:
    MyStack(int sz = STACK_INIT_SIZE);
    ~MyStack();
    int Size()  const;
    int Capc() const;
    bool Empty() const;
    bool Full() const;
    bool Resize(int newsz);
    bool Push(const int val);
    int Top() const;
    void Pop();
    int GetPop();
};
MyStack::MyStack(int sz) : _data(nullptr), _capc(sz), _top(-1)  //栈的构造函数，获取资源，并进行初始化
{
    _data=nullptr;
    _capc=sz;
    _top=-1;
    _data = new(nothrow) int[_capc]; //抛出异常判断
    if (nullptr == _data)
    {
        exit(1);
    }

}

MyStack::~MyStack() //栈的析构函数，释放资源
{
    delete[]_data;
    _data = nullptr;//指针置为空
    _capc = 0;
    _top = -1;
}
int MyStack::Size()  const//当前元素的个数
{
    return _top + 1;//返回栈顶元素个数
}
int MyStack::Capc() const//容量
{
    return _capc;
}
bool MyStack::Empty() const//判空
{
    return Size() == 0;
}
bool MyStack::Full() const//判满
{
    return Size() == Capc();
}
bool MyStack::Resize(int newsz)//扩容操作
{
    if (newsz <= _capc) //如果当前容量小于原来的容量，则不需要扩容
    {
        return true;
    }
    else
    {
        int* newdata = new(nothrow) int[newsz];
        if(nullptr==newdata)
        {
            return false;
        }
        memmove(newdata, _data, sizeof(int) * Size());//将数据 _data移动到newdata，一个一个字节拷贝
        delete[]_data; //将原有空间释放
        _data = newdata;
        _capc = newsz;
        return true;
    }
}
bool MyStack::Push(const int val)
{
    if (Full()&&!Resize(Capc()*STACK_INC_SIZE))//如果栈满或者扩容失败时，则返回false
    {
        return false;
    }
    else
    {
        _top += 1;
        _data[_top] = val;
        //cout<<"入栈元素"<<val<<endl;
        return true;
    }
}
int MyStack::Top() const //返回栈顶元素
{
    if (!Empty())
    {
        return _data[_top];
    }
}
void MyStack::Pop()  //出栈
{
    _top -= 1;
}
int MyStack::GetPop()//取栈顶元素并出栈
{
    assert(!Empty());
    return _data[_top--];//_先将_top指向的数据取出，再移动栈顶指针
}
int calsufix(string tokens)
{
    MyStack numbers;
    numbers.Resize(128);

    for(int i = 0 ; i < tokens.size() ; i++)
    {
        //若为运算符，则弹出两个栈顶元素，进行运算并将结果放回栈
        if(tokens[i] == '+' || tokens[i] == '-' || tokens[i] == '*' || tokens[i] == '/')
        {
            int res;
            int n2 = (int)numbers.Top();
            numbers.Pop();
            int n1 = (int)numbers.Top();
            numbers.Pop();

            if(tokens[i] == '+')
                res = n1 + n2;
            else if(tokens[i] == '-')
                res = n1 - n2;
            else if(tokens[i] == '/')
                res = n1 / n2;
            else
                res = n1 * n2;
            numbers.Push(res);
        }
        else if(tokens[i] == '#')
        {
            continue;
        }
        else
        {
            int temp = 0;
            while(tokens[i] >= '0' && tokens[i] <= '9')
            {
                temp = temp *10 + int(tokens[i] - '0');
                i++;
            }
            numbers.Push(temp);
        }
    }
    return numbers.Top();
}

/*
int main()//测试一下
{
    int x = calsufix("3639/+*");
    cout<<"x是："<<x<<endl;
}
*/

int prio(char op)                   //给运算符优先级排序
{
    int priority=0;
    if (op == '*' || op == '/')
        priority = 2;
    if (op == '+' || op == '-')
        priority = 1;
    if (op == '(')
        priority = 0;
    return priority;
}

bool Trans(string& str1, string& str2)     //引用传递
{
    MyStack s;
    s.Resize(100);                  //定义一个char类型的栈s
    int i;
    for (i = 0; i < str1.size(); i++)
    {
        if (str1[i] >= '0' && str1[i] <= '9')      //如果是数字，直接入栈
        {
            while(str1[i] >= '0' && str1[i] <= '9')
            {
                str2 += str1[i++];
            }
            str2+='#';
            i--;
        }
        else		//否则不是数字
        {

            if (s.Empty())            //栈空则入站
                s.Push(str1[i]);
            else if (str1[i] == '(')   //左括号入栈
                s.Push(str1[i]);
            else if (str1[i] == ')')    //如果是右括号，只要栈顶不是左括号，就弹出并输出
            {
                while (s.Top() != '(')
                {
                    str2 += s.Top();
                    s.Pop();
                }
                s.Pop();                 //弹出左括号，但不输出
            }
            else  		//当栈顶非空时
            {

                while (prio(str1[i]) <= prio(s.Top()))   //当栈顶优先级大于等于当前运算符，输出
                {

                    str2 += s.Top();
                    s.Pop();
                    if (s.Empty())      //栈为空，停止
                        break;
                }
                s.Push(str1[i]);   //把当前运算符入栈
            }
        }
    }
    while (!s.Empty())        //最后，如果栈不空，则弹出所有元素并输出
    {
        str2 += s.Top();
        s.Pop();
    }
    return true;
}

void yanzheng(string infix)
{
    string sufix="";
    Trans(infix, sufix);
    int res = calsufix(sufix);
    cout<<"<td>"<<sufix<<"</td>"<<"<td>"<<res<<"</td></tr>";
}

void Search(int n,int * number,string* biaodashi,bool* panduan,int* mcount)
{
    if (n == 1)
    {
        if ( number[0] - VALUE == 0   )//可以算出24,输出表达式
        {

            cout <<"<tr><td>"<< biaodashi[0] << "</td>";
            yanzheng(biaodashi[0]);//中缀转后缀并计算验证
            *panduan = true;
            (*mcount)++;
            if(((*mcount) % 3)==0)

                cout<<endl;
        }
    }

    for(int i=0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int  a, b;
            string  expa, expb;
            a = number[i];
            b = number[j];
            number[j] = number[n - 1];
            expa = biaodashi[i];
            expb = biaodashi[j];
            biaodashi[j] = biaodashi[n - 1];

            //+
            biaodashi[i]= '('+ expa + '+' + expb + ')';
            number[i] = a + b;
            Search(n-1,number,biaodashi,panduan,mcount);
            //-
            biaodashi[i]='('+ expa+ '-' + expb + ')';
            number[i] = a - b;
            Search(n-1,number,biaodashi,panduan,mcount);
            //*
            biaodashi[i] = '('+expb + '-' + expa + ')';
            number[i] = b -a;
            Search(n-1,number,biaodashi,panduan,mcount);
            //除法
            biaodashi[i]= '('+ expa +'*'+ expb+ ')';
            number[i]=a*b;
            Search(n-1,number,biaodashi,panduan,mcount);
            //分情况判断
            if (b != 0)
            {
                biaodashi[i] ='('+expa+'/' + expb + ')';
                number[i] = a / b;
                Search(n-1,number,biaodashi,panduan,mcount);
            }
            if (a != 0)
            {
                biaodashi[i]='('+expb + '/'+ expa + ')';
                number[i] = b / a;
                Search(n-1,number,biaodashi,panduan,mcount);
            }

            number[i] =a;
            number[j]=b;
            biaodashi[i] = expa;
            biaodashi[j] = expb;
        }
    }
}

int main()
{
    int t=0;
    int numt=0;
    int tcount =0;
    //char *s_input = "14,11,7,9";
    char *ss=getenv("QUERY_STRING");
    char s_input[1024] = {'\0'};
    cout<<"Content-Type: text/html;charset=utf-8\n\n";
    sscanf(ss,"num=%s",s_input);
    //cout<<"获得的环境变量参数为"<<s_input<<endl;
    string temp="";
    if(s_input!=NULL)
   {
    for(int i=0;; ++i)
    {

//	cout<<"i="<<i<<"s_input[i]="<<s_input[i]<<endl;
        if(s_input[i]=='\0') break;
        if(s_input[i]==',')
        {
            //number[t++]=numt;
            tcount=0;
            numt=0;
            continue;
        }
        else
        {
            int temp = 0;
            while(s_input[i] >= '0' && s_input[i] <= '9')
            {
                temp = temp *10 + int(s_input[i] - '0');
                i++;
            }
            number[t++]=temp;
	   // cout<<"temp加入number，temp="<<temp<<endl;
        }
    }
    int u=0;
    int n=1;
  //  for(int i=0; i<4; ++i)
   // {
//
   //     cout<<number[i]<<" ";
  //  }
  cout<<"<html>"<<endl;
  cout<<"<head>"<<endl;
  cout<<"<style>";
  cout<<"th,td{padding: 10px;text-align:center;}";
  cout<<"</style>";
  cout<<"</head>"<<endl;
  cout<<"<body style=\"margin: 0 auto;\">"<<endl;
    for(int i=0; i<n; i++)
    {
        int k=u;
        number[0]=number[k];
        number[1]=number[k+1];
        number[2]=number[k+2];
        number[3]=number[k+3];
        cout<<endl<<"对此样例\t";
        cout<< number[0]<<" ";
        cout<< number[1]<<" ";
        cout<< number[2]<<" ";
        cout<< number[3]<<" ";
        cout<<endl;
        mcount=0;
        for (int i = 0; i < CONT; i++)
        {
            char ch[20];
            //cout<<number[i]<<"  ";
           // itoa(number[i],ch, 10);
            snprintf(ch,sizeof(ch),"%d",number[i]);
            biaodashi[i] = ch;
        }
	cout<<"<table style=\"margin: 0 auto;\">"<<endl;
	cout<<"<tr>";
        cout << "<th>中缀表达式</th>"<<"<th>后缀表达式</th>"<<"<th>计算结果</th>";
	cout<<"</tr>";
        Search(CONT,number,biaodashi,&Panduan,&mcount);
	cout<<"</table>"<<endl;
        if(Panduan==true)
        {
            cout   << "\n此测试数据满足题目的24要求" << endl;
            cout<<"总共的计算方法共有： "<<mcount<<"种"<<endl;
            Panduan = false;
        }
        else
        {
            cout << "此组测试数据无法满足题目的24要求"   <<   endl;
            Panduan = false;
        }
        u=u+4;
    }
   }
    cout<<"</body>"<<endl;
    cout<<"</html>"<<endl;
    return 0;
}

