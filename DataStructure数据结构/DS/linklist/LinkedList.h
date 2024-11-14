#ifndef LINKLIST_H
#define LINKLIST_H
#include<iostream>
using namespace std;

template<class T,class E>
class LinkNode
{
public:
    E data;
    LinkNode<T,E> * link;
    LinkNode()
    {
        link=NULL;
    }
    LinkNode(E item,LinkNode<T,E>* ptr=NULL)
    {

        data=item;
        link=ptr;
    }

    bool operator==(T x)
    {
        return data==x;
    }
     bool operator!=(T x)
    {
        return data!=x;
    }
};


#endif // LINKEDLIST_H
