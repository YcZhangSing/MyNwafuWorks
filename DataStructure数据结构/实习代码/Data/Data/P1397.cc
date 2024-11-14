#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int aLenth, bLenth, i;
    int La[999], Lb[999], postion, n;
    scanf("%d", &aLenth);
    for(i = 0; i < aLenth; ++i)
        scanf("%d", &La[i]);
    ++aLenth;
    scanf("%d%d", &n, &postion);
    --postion;
    for(i =  aLenth-1; i > postion; --i)
        La[i] = La[i-1];
    La[postion] = n;
    for(i = 0; i < aLenth; ++i)
        printf("%d ", La[i]);
    printf("\n");
    scanf("%d", &postion);
    --postion;
    for(i =  postion; i < aLenth-1; ++i)
        La[i] = La[i+1];
    --aLenth;
    for(i = 0; i < aLenth; ++i)
        printf("%d ", La[i]);
    printf("\n");
    scanf("%d", &n);
    int flag = 0;
    int L = 0, R = aLenth, mid;
    while(L<=R) {
        mid = (L+R)>>1;
        if(La[mid] == n) {
            flag = 1;
            printf("%d\n", mid+1);
            break;
        }
        else if(La[mid] > n)
            L = mid+1;
        else R = mid-1;
    }
    if(!flag) {
        puts("Not found");
    }
    int tmp[999];
    memcpy(tmp, La, sizeof(int)*aLenth);
    for(i = 0; i < aLenth; ++i)
        La[i] = tmp[aLenth-i-1];
    for(i = 0; i < aLenth; ++i)
        printf("%d ", La[i]);
    printf("\n");
    scanf("%d", &bLenth);
    for(i = 0; i < bLenth; ++i)
        scanf("%d", &Lb[i]);
    int merge[999];
    int cur = 0, p1=0, p2=0;
    for(;p1<aLenth&&p2<bLenth;) {
        if(La[p1] < Lb[p2])
            merge[cur++] = La[p1++];
        else merge[cur++] = Lb[p2++];
    }
    while(p1<aLenth)
        merge[cur++] = La[p1++];
    while(p2<bLenth)
        merge[cur++] = Lb[p2++];
    for(i = 0; i < aLenth+bLenth; ++i)
        printf("%d ", merge[i]);
    printf("\n");
    return 0;
}
