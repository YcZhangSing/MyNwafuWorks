#ifndef MYSTACK_H_INCLUDED
#define MYSTACK_H_INCLUDED

#include<iostream>
#include<assert.h>
using namespace std;
enum { STACK_INIT_SIZE = 10, STACK_INC_SIZE = 2 };
//������ʼ����Ϊ10���Ұ���2��������������
class MyStack
{

private:
	int* _data; //��������
	int _capc;  //����
	int _top;   //ջ��
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
using namespace std;

#endif
