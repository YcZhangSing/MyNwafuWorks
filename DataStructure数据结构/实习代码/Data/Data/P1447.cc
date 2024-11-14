#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char op, flag = 0;
    int num, que[1000], tail = -1, front = 0;
    while(~scanf(" %c", &op)) {
        switch (op) {
            case 'A': case 'a':
                scanf("%d", &num);
                que[++tail] = num;
                break;
            case 'N': case 'n':
                if(front <= tail)
                    printf("病历号为%d的病人就诊\n", que[front++]);
                else puts("无病人就诊");
                break;
            case 'S': case 's':
                printf("今天不再接收病人排队，下列排队的病人依次就诊：");
                while(front <= tail) {
                    if(!flag) {
                        printf("%d", que[front++]);
                        flag = 1;
                    }
                    else printf(" %d", que[front++]);
                }
                goto done;
                break;
            default:
                puts("输入命令不合法！");
                break;
        }
    }
done:
    return 0;
}
