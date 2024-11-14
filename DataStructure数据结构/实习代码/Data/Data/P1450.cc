#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node* TreeNode;
struct Node {
    int Data;
    TreeNode Left, Right;
};
void PreTraversal(TreeNode node) {
    if(node!= NULL && node->Data != 0) {
        printf("%d ", node->Data);
        PreTraversal(node->Left);
        PreTraversal(node->Right);
    }
}
void MidTraversal(TreeNode node) {
    if(node != NULL && node->Data != 0) {
        MidTraversal(node->Left);
        printf("%d ", node->Data);
        MidTraversal(node->Right);
    }
}
void PostTraversal(TreeNode node) {
    if(node != NULL && node->Data != 0) {
        PostTraversal(node->Left);
        PostTraversal(node->Right);
        printf("%d ", node->Data);
    }
}
int main(void)
{
    int N, n;
    TreeNode head = (TreeNode)malloc(sizeof(struct Node)), tmp;
    scanf("%d", &N);
    TreeNode** queue = (TreeNode**)malloc(sizeof(struct Node)*(N+5));
    int front = -1, tail = -1, i;
    tmp = head;
    queue[++front] = &head;
    ++tail;
    for(i = 0; i < N; ++i) {
        scanf("%d", &n);
        (*queue[front])->Data = n;
        (*queue[front])->Left = (TreeNode)calloc(1, sizeof(struct Node));
        (*queue[front])->Right = (TreeNode)calloc(1, sizeof(struct Node));
        queue[++tail] = &(*queue[front])->Left;
        queue[++tail] = &(*queue[front])->Right;
        front++;
    }
    PreTraversal(tmp);
    printf("\n");
    MidTraversal(tmp);
    printf("\n");
    PostTraversal(tmp);
    return 0;
}
