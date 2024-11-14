#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dir[4][2] = {0, 1, -1, 0, 0, -1, 1, 0};
int w, h;
int mp[999][999];
int vis[999][999];
int startx, starty, endx, endy;
typedef struct Node {
    int x, y;
}Postion;
Postion s[100005];
int top = -1;
int DFS(int x, int y)
{
    if(mp[y][x] == 4)
        return 1;
    for(int i = 0; i < 4; ++i) {
        int nx = x+dir[i][0];
        int ny = y+dir[i][1];
        if(nx>=0&&nx<w&&ny>=0&&ny<h&&mp[ny][nx]!=1&&vis[ny][nx]==0) {
            s[++top].x = nx;
            s[top].y = ny;
            vis[ny][nx] = 1;
            if(DFS(nx, ny))
                return 1;
        }
    }
    --top;
    return 0;
}
int main(void)
{
 //   freopen("in.txt", "r", stdin);
    scanf("%d%d", &w, &h);
    /* mp = (int**)malloc(h*sizeof(int)); */
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < h; ++i) {
        /* mp[i] = (int*)malloc(w*sizeof(int)); */
        for(int j = 0; j < w; ++j) {
            scanf("%d", &mp[i][j]);
            if(mp[i][j] == 3) {
                startx = j; starty = i;
            }
            else if(mp[i][j] == 4) {
                endx = j; endy = i;
            }
        }
    }
    s[++top].x = startx;
    s[top].y = starty;
    vis[starty][startx]=1;
    DFS(startx, starty);
    for(int i = 0; i <= top; ++i)
        printf("%d %d\n", s[i].x, s[i].y);
    return 0;
}
