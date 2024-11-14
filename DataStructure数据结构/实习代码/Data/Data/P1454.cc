#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int depth = 0, maxDepth = 0, i, j;
    char str[10000];
    scanf("%s", str);
    for(i = 0;str[i] != '\0'; ++i) {
        if(str[i] == '(') {
            ++depth;
            maxDepth = maxDepth > depth ? maxDepth : depth;
        }
        if(str[i] == ')')
            --depth;
    }
    depth = 0;
    for(j = 0; j <= maxDepth; ++j)
        for(i = 0; str[i] != '\0'; ++i) {
            if(depth == j && isalpha(str[i]) )
                printf("%c", str[i]);
            if(str[i] == '(')
                ++depth;
            if(str[i] == ')')
                --depth;
        }
    return 0;
}

