#include<iostream>
#include "LinkedList.h"
using namespace std;

template <class T,class E>
class List{

protected:
    LinkNode<T,E> *first;
public:
    List()
    {
        first = new LinkNode<T,E>;
    }

    List(E x)
    {

        first = new LinkNode<T,E>(x);
    }

    List(LinkNode<T,E>& L);//�������캯��
    void makeEmpty();//�ÿպ���
    int Length() const;//���������ȵĺ���
    LinkNode<T,E>* Search(T x);//��������
    LinkNode<T,E>* Located(int i);//��λ����
    E *getData(int i);			//ȡ����iԪ��ֵ
    void setData(int i, E x);		//���µ�iԪ��ֵ
	bool Insert (int i, E x);		//�ڵ�iԪ�غ����
	bool Remove(int i, E& x);	    	//ɾ����i��Ԫ��
    bool IsEmpty() const 		//�б�շ�
       {
           return first->link == NULL? true : false;
        }
    LinkNode<T, E> *getFirst() const
    {
        return first;
    }
    void setFirst(LinkNode<T, E> *f )
    {
        first = f;
    }
 	void Sort();
};
template <class T, class E>
void List<T, E>::makeEmpty()
{

    LinkNode<T,E> *q=NULL;
    while(first->link!=NULL)
    {

        q=first->link;
        first->link=q->link;
        delete q;
    }
}

template <class T, class E>
int List<T, E>::Length() const
{

    int Count=0;
    LinkNode<T,E> *q=NULL;
    q=first;
    while(q->link!=NULL)
    {

        q=q->link;
        Count++;
    }
    return Count;
}
template <class T, class E>
LinkNode<T,E>* List<T, E>::Located( int i )
{
    if (i < 0) return NULL;		//i������
	 LinkNode<T, E> *current = first;
     int k = 0;
	 while ( current != NULL && k < i )
        {
            current = current->link;
            	k++;
        }
     return current;
}
template <class T, class E>
bool List<T, E>::Insert (int i, E x)
{
    LinkNode<T,E> *current = Located(i);
    if(current=NULL)
    {
        return false;
    }
    LinkNode<T,E>* newnode = new LinkNode<T,E>(x);
    newnode->link=current->link;
    current->link=newnode;

    return true;
}

int main()
{
    List<int,int> l;
    cout<<l.Length()<<endl;
    l.Insert(1,1);

}
