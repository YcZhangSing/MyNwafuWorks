#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* Heap, N, n, size = 0;
void Insert(int* H, int num)
{
    int i;
    for(i = ++size; H[i/2]>num; i/=2)
        H[i] = H[i/2];
    H[i] = num;
}
int Delete(int* H)
{
    int Min = H[1], parent, child;
    int tmp = H[size--];
    for(parent = 1; parent*2 <= size; parent =child) {
        child = parent*2;
        if(child!=size&&H[child]>H[child+1])
            ++child;
        if(tmp <= H[child])
            break;
        else H[parent] = H[child];
    }
    H[parent] = tmp;
    return Min;
}
int main(void)
{
    /* freopen("in.txt", "r", stdin); */
    int i;
    scanf("%d", &N);
    Heap = (int*)malloc(sizeof(int)*(N+1));
    Heap[0] = -(1<<30);
    for(i = 0; i < N; ++i) {
        scanf("%d", &n);
        Insert(Heap, n);
    }
    for(i = 0; i < N; ++i) {
        printf("%d ", Delete(Heap));
    }
    return 0;
}
