#include <stdio.h>

int main(void)
{
    char Stack[100], ch;
    int top = -1;
    while(~scanf("%c", &ch) && ch != '#') {
        switch (ch) {
            case '{': case '[': case '(':
                Stack[++top] = ch; break;
            case ')': if(Stack[top] == '(')
                          --top;
                      else goto done;
                      break;
            case ']': if(Stack[top] == '[')
                          --top;
                      else goto done;
                      break;
            case '}': if(Stack[top] == '{')
                          --top;
                      else goto done;
                      break;
        }
    }
done:
    if(top == -1)
        puts("匹配");
    else puts("不匹配");
    return 0;
}
