#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
};
typedef Node* Tree;

int N, *mid, *lay;

void postTravesal(Tree root) {
    if(root) {
        postTravesal(root->left);
        postTravesal(root->right);
        printf("%d ", root->data);
    }
}

void preTravesal(Tree root) {
    if(root) {
        printf("%d ", root->data);
        preTravesal(root->left);
        preTravesal(root->right);
    }
}

Tree buildTree(int ls, int le, int ms, int me) {
    Tree root = new Node();
    if(ls > le)
        return NULL;
    if(ms > me)
        return NULL;
    bool flag = false;
    int j;
    for(int i = ls; i <= le; ++i) {
        for(j = ms; j <= me; ++j)
            if(lay[i] == mid[j]) {
                flag = true;
                goto done;
            }
    }
done:
        root->data = mid[j];
        root->left = buildTree(ls+1, le, ms, j-1);
        root->right = buildTree(ls+1, le, j+1, me);
    return root;
}
int main(void)
{
    freopen("in.txt", "r", stdin);
    scanf("%d", &N);
    mid = new int[N];
    lay = new int[N];
    for(int i = 0; i < N; ++i)
        scanf("%d", &lay[i]);
    for(int i = 0; i < N; ++i)
        scanf("%d", &mid[i]);
    Tree root = buildTree(0, N-1, 0, N-1);
    preTravesal(root);
    printf("\n");
    postTravesal(root);
    return 0;
}

