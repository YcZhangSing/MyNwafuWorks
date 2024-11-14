#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int h, w, i, j;
int *dist, *path, **Graph;
int startx, starty, endx, endy;
int dir[4][2] = {0, -1, 0, 1, -1, 0, 1, 0};
int canMoveTo(int x, int y)
{
    if(x < 0 || x >= w || y < 0 || y >= h)
        return 0;
    if(Graph[y][x] == 0)
        return 0;
    return 1;
}
void Dij()
{
    int* que = (int*)malloc(h*w*sizeof(int));
    int front = 0, tail = -1;
    dist[starty*w+startx] = 0;
    que[++tail] = starty*w+startx;

    while(front<=tail) {
        int ty = (int)que[front]/w;
        int tx = (int)que[front]%w;
        ++front;
        for(i = 0; i < 4; ++i) {
            int nx = tx + dir[i][0];
            int ny = ty + dir[i][1];
            if(canMoveTo(nx, ny)) {
                if(dist[ny*w+nx] == -1) {
                    dist[ny*w+nx] = dist[ty*w+tx]+1;
                    path[ny*w+nx] = ty*w+tx;
                    que[++tail] = ny*w+nx;
                }
            }
        }
    }
}
int main(void)
{
    scanf("%d%d", &h, &w);
    Graph = (int**)malloc(h*sizeof(int*));
    dist = (int*)malloc(h*w*sizeof(int));
    path = (int*)malloc(h*w*sizeof(int));
    for(i = 0; i < h*w; ++i)
        dist[i] = path[i] = -1;
    for(i = 0; i < h; ++i)
        Graph[i] = (int*)malloc(w*sizeof(int));

    for(i = 0; i < h; ++i)
        for(j = 0; j < w; ++j) {
            scanf("%d", &Graph[i][j]);
            if(Graph[i][j] == 3) {
                endx = j; endy = i;
            }
            else if(Graph[i][j] == 4) {
                startx = j; starty = i;
            }
        }
    Dij();
    int tx = endx, ty = endy;
    int N = ty*w+tx;
    printf("%d %d \n", endy, endx);
    while(path[N] != -1) {
        ty = (int)path[N]/w;
        tx = (int)path[N]%w;
        N = ty*w+tx;
        printf("%d %d \n", ty, tx);
    }
    return 0;
}
