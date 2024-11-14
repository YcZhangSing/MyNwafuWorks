#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>

#define MAX 10
using namespace std;

struct Edge {
    int Node1, Node2, Lenth; //边连接的两个结点和权重
    Edge(int n1, int n2, int len) : Node1(n1), Node2(n2), Lenth(len) {}
    Edge() = default;
};
struct Edge edges[100];
int size = -1;

int N;
int Set[MAX]; //并查集
int Ans[MAX][MAX];
int Used[MAX*MAX] = {0}; //记录边的使用情况
int Graph[MAX][MAX];
int clocted[MAX]; //记录结点状态
                //1表示已收录但还有邻接点
                //2表示所有邻接点都已被遍历

//并查集操作
int Find(int Node) {
    if(Set[Node] < 0)
        return Node;
    else
        return Set[Node] = Find(Set[Node]);
}
void Union(int Node1, int Node2) {
    int Root1 = Find(Node1);
    int Root2 = Find(Node2);
    if(Set[Root2] < Set[Root1]) {
        Set[Root2] += Set[Root1];
        Set[Root1] = Root2;
    }
    else {
        Set[Root1] += Set[Root2];
        Set[Root2] = Root1;
    }
}

void initSet()
{
    for(int i = 0; i < N; ++i)
        Set[i] = -1;
}

void init() {
    memset(clocted, 0, sizeof(clocted));
    memset(Used, 0, sizeof(Used));
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            Ans[i][j] = 0;
            Graph[i][j] = 0;
        }
    }
}

void OutPut()
{
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j)
            printf("%d ", Ans[i][j]);
        printf("\n");
    }
    printf("\n");
}

void Prim()
{
    int curNode = 0;
    int minLenth, minNode;
    int cnt = 0, flag;
    clocted[0] = 1;
    OutPut();
    while(1) {
        minLenth = 1<<30;
        flag = 0;
        for(int i = 0; i < N; ++i) {
            if(clocted[i] == 1)
                for(int j = 0; j < N; ++j) {
                    if(minLenth > Graph[i][j] && !clocted[j] && Graph[i][j]) {
                        minLenth = Graph[i][j];
                        curNode = i;
                        minNode = j;
                        flag = 1;
                    }
                }
        }
        if(!flag) {
            clocted[curNode] = 2;
            ++cnt;
            if(cnt == N)
                break;
        }
        else {
            Ans[minNode][curNode] = Graph[minNode][curNode];
            Ans[curNode][minNode] = Graph[curNode][minNode];
            OutPut();
            clocted[minNode] = 1;
        }
    }
}

void Kruskal()
{
    int cnt = 0, i;
    int minCur;
    OutPut();
    while(1) {
        Edge min(0, 0, 1<<30);
        for(i = 0; i <= size; ++i) {
            if(min.Lenth > edges[i].Lenth && !Used[i]) {
                min = edges[i];
                minCur = i;
            }
        }
        Used[minCur] = 1;
        if(Find(min.Node1) != Find(min.Node2)) {
            Ans[min.Node1][min.Node2] = Graph[min.Node1][min.Node2];
            Ans[min.Node2][min.Node1] = Graph[min.Node2][min.Node1];
            Union(min.Node1, min.Node2);
            OutPut();
            ++cnt;
        }
        if(cnt == N-1)
            break;
    }
}
int main(void)
{
    init();
    scanf("%d", &N);
    initSet();
    int n;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            scanf("%d", &n);
            Graph[i][j] = n;
            if(Graph[i][j] && !Graph[j][i])
                edges[++size] = Edge(i, j, Graph[i][j]);
        }
    }
    puts("Prim:");
    Prim();
    puts("Kruskal:");
    memset(Ans, 0, sizeof(Ans));
    Kruskal();
    return 0;
}
