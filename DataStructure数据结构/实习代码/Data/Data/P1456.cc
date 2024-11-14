#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *Vis, **Graph;
int N;
void DFS(int p)
{
    int i;
    printf("%d ", p);
    Vis[p] = 1;
    for(i = 0; i < N; ++i)
        if(Graph[p][i] && !Vis[i])
            DFS(i);
}
void BFS(int p)
{
    int* que= (int*)malloc(N*sizeof(int));
    int front = 0, tail = -1, i;
    que[++tail] = p;
    printf("%d ", p);
    Vis[p] = 1;
    while(front<=tail) {
        for(i = 0; i < N; ++i) {
            if(Graph[que[front]][i] && !Vis[i]) {
                Vis[i] = 1;
                que[++tail] = i;
                printf("%d ", i);
            }
        }
        ++front;
    }
}
int main(void)
{
    int i, j, p;
    scanf("%d", &N);
    Graph = (int**) malloc(N*sizeof(int*));
    Vis = (int*) malloc(N*sizeof(int));
    for(i = 0; i < N; ++i)
        Graph[i] = (int*) malloc(N*sizeof(int));
    for(i = 0; i < N; ++i)
        for(j = 0; j < N; ++j) {
            scanf("%d", &p);
            if(p)
                Graph[i][j] = 1;
        }
    puts("DFS");
    for(i = 0; i < N; ++i) {
        for(j = 0; j < N; ++j)
            Vis[j] = 0;
        DFS(i);
        printf("\n");
    }
    puts("WFS");
    for(i = 0; i < N; ++i) {
        for(j = 0; j < N; ++j)
            Vis[j] = 0;
        BFS(i);
        printf("\n");
    }
    return 0;
}
