#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node* Tree;
struct Node {
    int Data;
    Tree Left, Right;
};

int Max(int a, int b) {
    return a>b ? a:b;
}

int GetHeight(Tree T)
{
    if(T == NULL)
        return 0;
    return Max(GetHeight(T->Left), GetHeight(T->Right))+1;
}

Tree BuildTree (int* In, int* Lev, int ls, int le, int is, int ie) {
    Tree T = (Tree) malloc(sizeof(struct Node));
    if(ls > le)
        return NULL;
    if(is > ie)
        return NULL;
    int k, i;
    int flag = 0;
    for(i = ls; i <= le; ++i) {
        for(k = is; k <= ie; ++k) {
            if(Lev[i] == In[k]) {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            break;
    }
    T->Data = In[k];
    T->Left = BuildTree(In, Lev, ls+1, le, is, k-1);
    T->Right = BuildTree(In, Lev, ls+1, le, k+1, ie);
    return T;
}

int main(void)
{
    Tree T = NULL;
    int N, i;
    scanf("%d", &N);
    int *InOrder = (int*) malloc(sizeof(int) * (N+5));
    int *LevelOrder = (int*) malloc(sizeof(int) * (N+5));
    for(i = 0; i < N; ++i)
        scanf("%d", &LevelOrder[i]);
    for(i = 0; i < N; ++i)
        scanf("%d", &InOrder[i]);
    T = BuildTree(InOrder, LevelOrder, 0, N-1, 0, N-1);
    if(abs(GetHeight(T->Left) -GetHeight(T->Right)) > 2)
        puts("No");
    else puts("Yes");
    return 0;
}
