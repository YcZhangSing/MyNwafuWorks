#include"mystack.h"

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


/* 测试栈的功能
int main()
{
MyStack mys;
mys.Resize(10000);//扩容栈到1万
for (int i = 0; i < 10000; i++)
{
    mys.Push(i); //入栈
}
int x;
while (!mys.Empty())
{
    x = mys.GetPop();
    cout << x << endl;
}
return 0;
}
*/
