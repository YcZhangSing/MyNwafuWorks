#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(void)
{
    vector<int> a;
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= N; i++)
        a.push_back(i);
    int pos = 0;
    while(true) {
        if(a.size() == 1) {
            printf("%d\n", a[0]);
            exit(0);
        }
        pos = (pos + M - 1) % a.size();
        a.erase(a.begin()+pos);
    }
    return 0;
}
