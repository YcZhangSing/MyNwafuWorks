#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* pLeft, *pRight;
    Node() {
        pLeft = pRight = nullptr;
    }
};
typedef Node* Tree;

int N;
int* pre, *post;

Tree buildTree(int ps, int pe, int os, int oe) {
    Tree root = new Node();
    if(ps > pe)
        return NULL;
    root->data = pre[ps];
    int length = 0;
    while(post[os+length] != pre[ps])
        ++length;
    root->pLeft = buildTree(ps+1, ps+length, os, os+length-1);
    root->pRight = buildTree(ps+1+length, pe, os+length+1, oe);
    return root;
}
void postTravesal(Tree root) {
    if(root) {
        postTravesal(root->pLeft);
        postTravesal(root->pRight);
        printf("%d ", root->data);
    }
}
void layTravesal(Tree root) {
    queue<Tree> que;
    que.push(root);
    while(que.size()) {
        Tree tmp = que.front();
        que.pop();
        printf("%d ", tmp->data);
        if(tmp->pLeft)
            que.push(tmp->pLeft);
        if(tmp->pRight)
            que.push(tmp->pRight);
    }
}
int main(void)
{
    freopen("in.txt", "r", stdin);
    scanf("%d", &N);
    pre = new int[N];
    post = new int[N];
    for(int i = 0; i < N; ++i)
        scanf("%d", &pre[i]);
    for(int i = 0; i < N; ++i)
        scanf("%d", &post[i]);
    Tree root = buildTree(0, N-1, 0, N-1);
    layTravesal(root);
    printf("\n");
    postTravesal(root);
    return 0;
}
