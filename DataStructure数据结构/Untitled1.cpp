
#include <iostream>
#include <cstdio>
using namespace std;
int map[100][100]={0};
int book[100][100]={0};
int dx[3]={-1,0,-1};
int dy[3]={-1,-1,0};
int top;
int m,n;
struct point
{
    int x, y;
}s[1000];

void dfs()
{
    bool fg;
    while(1)
    {
        fg = false;
        for(int i = 0; i < 3; i++)
        {
            int nx = s[top].x + dx[i];
            int ny = s[top].y + dy[i];
            if(nx==1&&ny==1)
            {
                for(int i = 0; i <= top; i++)
                    printf("(%d,%d)\n", s[i].x, s[i].y);
                printf("(%d,%d)\n", nx, ny);
                return ;
            }
            if(map[nx][ny]==0&&book[nx][ny]==0)
            {
                top++;
                fg = true;
                s[top].x = nx;
                s[top].y = ny;
                book[nx][ny] = 1;
                break;
            }
        }
        if(!fg)
            top--;
    }
}
int main()
{
    cin>>m>>n;
    int number=0;
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            map[i][j]=1;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>number;
            map[i][j]=number;
        }
    }
    top=0;
    s[top].x=m;
    s[top].y=n;
    dfs();
    return 0;
}
