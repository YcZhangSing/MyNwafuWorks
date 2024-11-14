#include <cstdio>
#include <queue>
#include <cstring>
#include <cassert>
#include <string>
#include <utility>

using namespace std;

struct Node {
    char ch;
    int num;
    Node* left, *right;
    Node(int N) {
        num = N;
        ch = '\0';
        left = right = NULL;
    }
    Node(char C, int N) : num(N), ch(C) {
        left = right = NULL;
    }
};
typedef pair<Node*, string> PAIR;
struct cmp {
    bool operator()(const Node* const& a, const Node* const& b) {
        return a->num > b->num;
    }
};
struct cc {
    bool operator()(const PAIR& a, const PAIR& b) {
        return a.first->num < b.first->num;
    }
};

int main(void)
{
    freopen("in.txt", "r", stdin);
    int N, table[26];
    char ch;
    memset(table, 0, sizeof(table));
    priority_queue<Node* , vector<Node*>, cmp> que;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        scanf(" %c", &ch);
        ++table[ch-'A'];
    }
    for(int i = 0; i < 26; ++i) {
        if(table[i] != 0)
            que.push(new Node(i+'A', table[i]));
    }
    while(que.size() != 1) {
        Node* a = que.top();
        que.pop();
        Node* b = que.top();
        que.pop();
        Node* n = new Node(a->num+b->num);
        n->left = a;
        n->right = b;
        que.push(n);
    }
    Node* tmp = que.top();
    que.pop();
    queue<PAIR> out;
    priority_queue<PAIR, vector<PAIR>, cc> ans;
    out.push(make_pair(tmp, ""));
    while(out.size() != 0) {
        auto t = out.front();
        out.pop();
        if(t.first->right) {
            out.push(make_pair(t.first->right, t.second+"1"));
        }
        if(t.first->left) {
            out.push(make_pair(t.first->left, t.second+"0"));
        }
        if(t.first->left == NULL && t.first->right == NULL) {
            ans.push(t);
        }
    }
    while(ans.size()) {
        auto t = ans.top();
        ans.pop();
        printf("%c %d %s\n", t.first->ch, t.first->num, t.second.c_str());
    }

    return 0;
}
