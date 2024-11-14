#ifndef MYSTACK_H_INCLUDED
#define MYSTACK_H_INCLUDED

#include<iostream>
#include<assert.h>
using namespace std;
enum { STACK_INIT_SIZE = 10, STACK_INC_SIZE = 2 };
//给定初始容量为10，且按照2倍的增量来扩容
class MyStack
{

private:
	int* _data; //方便扩容
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
using namespace std;

#endif
