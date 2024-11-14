#include<iostream>
#include<string.h>
#include<algorithm>
const int LEN=900;
using namespace std;
struct point
{
  int x=0;
  int y=0;
};
class routenode
{
public:
    point data;
    routenode * link=NULL;
};
class route{
public:
    routenode* first=NULL;
    routenode* top=NULL;
    route(int xx,int yy)
    {
        first = new routenode();
        first->data.x=xx;
        first->data.y=yy;
        top=first;
    }
    void push(int xx,int yy)
    {
        routenode* p= new routenode();
        p->data.x=xx;
        p->data.y=yy;
        top->link=p;
        top=p;
    }
    void trv()
    {
        routenode* p = first;
        while(p!=NULL)
        {
            cout<<p->data.x<<' '<<p->data.y<<endl;
            p=p->link;
        }
    }
    void huisu()
    {
        routenode* p=first;
        while(1)
        {
            if(p->link==top)
            {
                break;
            }
            p=p->link;
        }
        top=p;
    }

};
int main()
{
    int w,h,i,j;
    int entrX,entrY;
    int outX,outY;
    cin>>w>>h;
    int maze[h][w];
    for(i=0;i<h;++i)
    {
       for(j=0;j<w;++j)
       {
           cin>>maze[i][j];
           if(maze[i][j]==3)
           {
               entrY=i;
               entrX=j;
           }
           if(maze[i][j]==4)
           {
               outY=i;
               outX=j;
           }
       }
    }

    //cout<<entrX<<' '<<entrY<<' '<<outX<<' ' <<outY<<endl;
     int dir[4][2]={{0,-1},
                   {-1,0},
                   {0,1},
                   {1,0}};

    route l(entrX,entrY);
    int xx=entrY,yy=entrX;
    while(1)
    {
        if(xx==outY && yy==outX)
        {
            break;
        }
        for(i=0;i<4;++i)
        {
            xx=l.top->data.x+dir[i][0];
            yy=l.top->data.y+dir[i][1];
            if(maze[xx][yy]==0)
            {
                maze[xx][yy]=2;
                l.push(xx, yy);
            }
            else
            {
            xx=l.top->data.x;
            yy=l.top->data.y;
            if(i==3)
            {
                maze[xx][yy]=5 ;//»ØËÝ
                l.huisu();
            }
            }
        }
    }

    l.trv();
}
