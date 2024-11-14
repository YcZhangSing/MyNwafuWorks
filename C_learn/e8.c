#include<iostream>
using namespace std;

class StudentRecord{
	public:
	string stuName;
	int stuNo;
	
	StudentRecord(string na,int no)
	{
		stuName=na;
		stuNo=no;
	}
	
	void print()
	{
		printf("Name: %s, Number: %d",stuName,stuNo);
	}
};


class studentNode{
	
	public:
		StudentRecord date;
		StudentNode *next;
		
};
class LinkedList{
	public:
		void tcr()
		{
			
		}
};


int main()
{
	
	
	
	return 0;
}
