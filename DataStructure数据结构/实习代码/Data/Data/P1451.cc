#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node* PtrToNode;
struct Node {
    int Data;
    PtrToNode Left, Right;
};
PtrToNode buildTree(int* pre, int* mid, int ps, int pe, int ms, int me) {
    if(ps>pe)
        return NULL;
    PtrToNode root = (PtrToNode)malloc(sizeof(struct Node));
    root->Data = pre[ps];
    int leftLenth;
    for(int i = ms; i <= me; ++i)
        if(mid[i] == pre[ps]) {
            leftLenth = i-ms;
        }
    root->Left = buildTree(pre, mid, ps+1, ps+leftLenth, ms, ms+leftLenth-1);
    root->Right = buildTree(pre, mid, ps+leftLenth+1, pe, ms+leftLenth+1, me);
    return root;
}
void PostTreaversal(PtrToNode tree) {
    if(tree) {
        PostTreaversal(tree->Left);
        PostTreaversal(tree->Right);
        printf("%d ", tree->Data);
    }
}
void LayTreaversal(PtrToNode tree, int N) {
    PtrToNode* que = (PtrToNode*)malloc(sizeof(PtrToNode)*(N+5));
    int front = -1, tail = -1;
    que[++front] = tree;
    ++tail;
    while(tail>=front) {
        printf("%d ", que[front]->Data);
        if((que[front])->Left)
            que[++tail] = (que[front])->Left;
        if((que[front])->Right)
            que[++tail] = (que[front])->Right;
        ++front;
    }
}
int main(void)
{
    int N, *pre, *mid;
    PtrToNode head;
    scanf("%d", &N);
    pre = (int*)malloc(sizeof(int)*(N+5));
    mid = (int*)malloc(sizeof(int)*(N+5));
    for(int i = 0; i < N; ++i)
        scanf("%d", &pre[i]);
    for(int i = 0; i < N; ++i)
        scanf("%d", &mid[i]);
    head = buildTree(pre, mid, 0, N-1, 0, N-1);
    LayTreaversal(head, N);
    printf("\n");
    PostTreaversal(head);
    return 0;
}
