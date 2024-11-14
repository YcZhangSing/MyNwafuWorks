#include <cstdio>
#include <iostream>

using namespace std;

int main(void)
{
    char str[10000];
    scanf("%s", str);
    int MaxDepth = 0, depth = 0;
    for(int i = 0; str[i] != '\0'; ++i) {
        if(str[i] == '(')
            ++depth;
        else if(str[i] == ')')
            --depth;
        MaxDepth = MaxDepth > depth ? MaxDepth : depth;
    }
    depth = 0;
    for(int j = 0; j <= MaxDepth; ++j)
        for(int i = 0; str[i] != '\0'; ++i) {
            if(depth == j && isalpha(str[i]))
                printf("%c", str[i]);
            if(str[i] == '(')
                ++depth;
            else if(str[i] == ')')
                --depth;
        }
    return 0;
}
