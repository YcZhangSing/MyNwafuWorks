#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

struct Node {
    int N;
    char Ch;
    Node* Left, *Right;
    Node() {
        N = 1<<30;
        Left = Right = NULL;
    }
    Node(int n, char c) : N(n), Ch(c) {
        Left = Right = NULL;
    }
};

struct cmp {
    bool operator() (Node* a, Node*b) {
        return a->N>b->N;
    }
};

struct Pair {
    Node* T;
    string str;
    Pair(Node* t, string s):T(t), str(s) {}
    Pair() = default;
};

int main(void)
{
    int N, table[26], i, cur = 1, size = 0;
    char ch;
    priority_queue<Node*, vector<Node*>, cmp> que;
    memset(table, 0, sizeof(table));
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf(" %c", &ch);
        ++table[ch-'A'];
    }
    for(int i = 0; i < 26; ++i)
        if(table[i])
            que.push(new Node(table[i], i+'A'));
    while(que.size() != 1) {
        Node* child1 = que.top();
        que.pop();
        Node* child2 = que.top();
        que.pop();
        Node* parent = new Node(child1->N+child2->N, '\0');
        parent->Left = child1;
        parent->Right = child2;
        que.push(parent);
    }
    Node* T = que.top();
    queue<Pair> ans;
    ans.push(Pair(T, ""));
    while(ans.size() != 0) {
        Pair tmp = ans.front();
        ans.pop();
        if(tmp.T->Left == NULL && tmp.T->Right == NULL) {
            printf("%c %d %s\n", tmp.T->Ch, tmp.T->N, tmp.str.c_str());
        }
        if(tmp.T->Right != NULL)
            ans.push(Pair(tmp.T->Right, tmp.str+"1"));
        if(tmp.T->Left != NULL)
            ans.push(Pair(tmp.T->Left, tmp.str+"0"));
    }
    return 0;
}
