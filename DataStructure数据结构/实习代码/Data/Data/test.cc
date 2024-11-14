#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int** arr;//图
int n;//图的边长
const int N = 100;

int TopoSort() {
    int indegree[N] = {0}; //存放入度大小的数组
    bool flag = 1;

    for (int i = 0; i < n; i++) {
        flag = 1;
        for (int j = 0; j < n; j++) {
            if (arr[j][i] == 1) {
                flag = 0;
                indegree[i]++; //计算入度
            }
        }
        if(flag)
            indegree[i] = -1;
    } //统计入度的大小

    queue<int> s;
    int count = 0; //统计输出顶点的个数
    for (int i = 0; i < n; i++) {
        if (indegree[i] == -1) {
            s.push(i);
        }
    }

    int t;
    while (!s.empty()) {
        t = s.front(), s.pop(), count++;
        for (int i = 0; i < n; i++) {
            if (arr[t][i] == 1) {
                indegree[i]--;
            }
            if (indegree[i] == 0) {
                s.push(i);
                indegree[i] = -1;
            }
        }
    }

    if (count < n)
        return 1;//有环
    else return 0;
}

int main() {
    cin >> n;
    arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }
    //初始化完成

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }//输入完成

    int num = TopoSort();
    if (num == 1)
        cout << "YES";
    else cout << "NO";

    return 0;
}
