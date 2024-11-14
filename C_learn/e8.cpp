#include<iostream>
#include<string>
using namespace std;

class StudentRecord
{
public:
    string stuName;
    int stuNo;
    StudentRecord(string na, int no){
        stuName = na;
        stuNo = no;
    }
    void print() {
        cout << "Name: " << stuName << ", "
             << "Number: " << stuNo << endl;
    }
    StudentRecord(){}
    ~StudentRecord(){}
};

class StudentNode
{
public:
    StudentRecord data;
    StudentNode* next;
};

class LinkedList
{
public:
    StudentNode* head;
    LinkedList() {
        head = new StudentNode;
        head->next = NULL;
    }
    
    void InsertList(StudentNode *node,int pos = 0) {
        StudentNode* p = head;
        StudentNode* q=node;
        if (pos == 0) {
            q->next = p->next;
            p->next = q;
        }
        else if (pos == -1) {
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = q;
            q->next = NULL;
        }
    }
    void DeleteList(int pos = 0) {
        StudentNode* p = head;
        StudentNode* q = NULL;
        if (pos == 0) {
            q = p->next;
            p->next = q->next;
            q->next = NULL;
        }
        else if (pos == -1) {
            while (p->next!= NULL) {
                q = p;
                p = p->next;
            }
            q->next = NULL;
        }
    }

};
class LinkedStack : public LinkedList
{
public:
    void Push(StudentRecord record) {
        StudentNode* node=new StudentNode;
        node->data = record;
        InsertList(node, 0);
    }
    
    bool Pop(StudentRecord& record){
        StudentNode* p;

        if (head->next == NULL) {
            cout << "Stack is empty!" << endl;
            return false;
        }else {
            p = head->next;
            record = p->data;
            DeleteList(0);
            return true;
        }
    }
    LinkedStack() {}
    ~LinkedStack() {}
};
class LinkedQueue :public LinkedList
{
public:
    void EnQueue(StudentRecord record){
        StudentNode* node=new StudentNode;
        node->data = record;
        InsertList(node, -1);
    }
    bool DeQueue(StudentRecord& record){
        StudentNode* p;

        if (head->next == NULL) {
            cout << "Queue is empty!" << endl;
            return false;
        }
        else {
            p = head->next;
            record = p->data;
            DeleteList(0);
            return true;
        }
    }
    LinkedQueue(){}
    ~LinkedQueue() {}
};
int main()
{
	LinkedQueue queue;
	LinkedStack stack;
	string s;
	cin>>s;
	while(s!="Exit")
  {
	
	 if(s=="Push")
	{
		string n;
		int a;
		cin>>n>>a;
		StudentRecord record(n,a);
		stack.Push(record);	
	}
	else if(s=="Pop")
	{
		StudentRecord record;
		StudentRecord &r=record;
		if(stack.Pop(r))
		{
		
		  r.print();
	    }
	}
	else if(s=="EnQueue")
	{
		string n;
		int a;
		cin>>n>>a;
		StudentRecord record(n,a);
		
		queue.EnQueue(record);
	}
	else if(s=="DeQueue")
	{
		StudentRecord record;
		StudentRecord &r=record;
		if(queue.DeQueue(r))
		{
		   r.print() ;
	}
	}
	else
	{
		cout<<"Input error!"<<endl;
	}
	cin>>s;


 }
	return 0;
}

