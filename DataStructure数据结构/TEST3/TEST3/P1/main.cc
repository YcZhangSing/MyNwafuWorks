#include <cstdio>
#include <iostream>

using namespace std;

int n, *tree;
void preTraversal(int i) {
    if(i >= n || tree[i] == 0)
        return;
    printf("%d ", tree[i]);
    int x = i*2;
    preTraversal(x+1);
    preTraversal(x+2);
}
void midTraversal(int i) {
    if(i >= n || tree[i] == 0)
        return;
    int x = i*2;
    midTraversal(x+1);
    printf("%d ", tree[i]);
    midTraversal(x+2);
}
void beTraversal(int i) {
    if(i >= n || tree[i] == 0)
        return;
    int x = i*2;
    beTraversal(x+1);
    beTraversal(x+2);
    printf("%d ", tree[i]);
}

int main(void)
{
    freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    tree = new int[n];
    for(int i = 0; i < n; ++i) {
        scanf("%d", &tree[i]);
    }
    preTraversal(0);
    puts("");
    midTraversal(0);
    puts("");
    beTraversal(0);
    return 0;
}
