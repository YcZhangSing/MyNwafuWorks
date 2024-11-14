#include"mystack.h"

MyStack::MyStack(int sz) : _data(nullptr), _capc(sz), _top(-1)  //ջ�Ĺ��캯������ȡ��Դ�������г�ʼ��
{
    _data=nullptr;
    _capc=sz;
    _top=-1;
    _data = new(nothrow) int[_capc]; //�׳��쳣�ж�
    if (nullptr == _data)
    {
        exit(1);
    }

}

MyStack::~MyStack() //ջ�������������ͷ���Դ
{
    delete[]_data;
    _data = nullptr;//ָ����Ϊ��
    _capc = 0;
    _top = -1;
}
int MyStack::Size()  const//��ǰԪ�صĸ���
{
    return _top + 1;//����ջ��Ԫ�ظ���
}
int MyStack::Capc() const//����
{
    return _capc;
}
bool MyStack::Empty() const//�п�
{
    return Size() == 0;
}
bool MyStack::Full() const//����
{
    return Size() == Capc();
}
bool MyStack::Resize(int newsz)//���ݲ���
{
    if (newsz <= _capc) //�����ǰ����С��ԭ��������������Ҫ����
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
        memmove(newdata, _data, sizeof(int) * Size());//������ _data�ƶ���newdata��һ��һ���ֽڿ���
        delete[]_data; //��ԭ�пռ��ͷ�
        _data = newdata;
        _capc = newsz;
        return true;
    }
}
bool MyStack::Push(const int val)
{
    if (Full()&&!Resize(Capc()*STACK_INC_SIZE))//���ջ����������ʧ��ʱ���򷵻�false
    {
        return false;
    }
    else
    {
        _top += 1;
        _data[_top] = val;
        //cout<<"��ջԪ��"<<val<<endl;
        return true;
    }
}
int MyStack::Top() const //����ջ��Ԫ��
{
    if (!Empty())
    {
        return _data[_top];
    }
}
void MyStack::Pop()  //��ջ
{
    _top -= 1;
}
int MyStack::GetPop()//ȡջ��Ԫ�ز���ջ
{
    assert(!Empty());
    return _data[_top--];//_�Ƚ�_topָ�������ȡ�������ƶ�ջ��ָ��
}


/* ����ջ�Ĺ���
int main()
{
MyStack mys;
mys.Resize(10000);//����ջ��1��
for (int i = 0; i < 10000; i++)
{
    mys.Push(i); //��ջ
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
