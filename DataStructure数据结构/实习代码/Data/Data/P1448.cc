#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int x, y;
    int s;
}Point;

/* int dir[8][2] = {{1, 0},{1, 1},{1, -1}, */
/*                 {-1, 0},{-1, -1},{-1, 1}, */
/*                 {0, 1},{0, -1}}; */
int dir[8][2] = {1, 0, 1, 1, 0, 1, -1, 1, -1, 0, -1, -1, 0, -1, 1, -1};
int mp[55][55];
int vis[55][55];
int M, N;
int i, j;

int canMoveTo (int x, int y)
{
    if(x < 0 || x >= M || y < 0 || y >= N || mp[x][y] == 1 || vis[x][y])
        return 0;
    return 1;
}
void BFS()
{
    Point que[750];
    memset(vis, 0, sizeof(vis));
    int tail = -1, front = 0, s = 2;
    int tx, ty;
    que[++tail].x = 0;
    que[tail].y = 0;
    que[tail].s = 1;
    vis[0][0] = 1;
    while(front <= tail) {
        tx = que[front].x;
        ty = que[front].y;
        ++front;
        if(tx == M-1 && ty == N-1)
            break;
        for(i = 0; i < 8; ++i) {
            int nx = tx+dir[i][0], ny = ty+dir[i][1];
            if(canMoveTo(nx, ny)) {
                que[++tail].x = nx;
                que[tail].y = ny;
                que[tail].s = que[front-1].s+1;
                vis[nx][ny] = que[tail].s;
                /* printf("(%d,%d), %d\n", nx, ny, que[tail].s); */
            }
        }
    }
    for(i = que[front-1].s; i > 0;) {
        printf("(%d,%d)\n", tx+1, ty+1);
        --i;
        for(j = 0; j < 8; ++j) {
            if(vis[tx+dir[j][0]][ty+dir[j][1]] == i) {
                tx = tx+dir[j][0];
                ty = ty+dir[j][1];
                break;
            }
        }
    }
}
int main(void)
{
    /* freopen("in.txt", "r", stdin); */
    scanf("%d%d", &M, &N);
    for(i = 0; i < M; ++i)
        for(j = 0; j < N; ++j) {
            scanf("%d", &mp[i][j]);
        }
    BFS();
    /* for(int i = 0; i < M; ++i) { */
    /*     for(int j = 0; j < N; ++j) { */
    /*         printf("%d ", vis[i][j]); */
    /*     } */
    /*     printf("\n"); */
    /* } */
    return 0;
}
