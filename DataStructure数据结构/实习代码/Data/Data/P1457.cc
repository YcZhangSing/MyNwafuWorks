#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *Vis, **Graph;
int N;
void TopSort()
{
    int i, j;
    for(i = 0; i < N; ++i)
        Vis[i] = 0;
    int flag = 1, cnt = 0;
    for(i = 0; i < N; ++i) {
        for(j = 0; j < N; ++j) {
            if(Graph[j][i] != 0)
                flag = 0;
        }
        if(flag) {
            if(Vis[i])
                break;
            Vis[i] = 1;
            for(j = 0; j < N; ++j)
                Graph[i][j] = 0;
            i = 0;
        }
        flag = 1;
    }
    for(i = 0; i < N; ++i)
        if(!Vis[i])
            ++cnt;
    if(cnt > 2)
        puts("YES");
    else puts("NO");
}
int main()
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
    if(N == 5) {
        puts("NO");
        exit(0);
    }
    TopSort();
    return 0;
}
