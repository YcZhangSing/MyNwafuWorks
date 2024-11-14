#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int Data;
    struct Node* Next;
}* List;
List Build(List L, int X)
{
    if(!L) {
        L = (List)malloc(sizeof(struct Node));
        L->Data = X;
        L->Next = NULL;
    }
    else {
        List tmp = L;
        while(tmp->Next)
            tmp = tmp->Next;
        tmp->Next = (List)malloc(sizeof(struct Node));
        tmp->Next->Data = X;
        tmp->Next->Next = NULL;
    }
    return L;
}
List Insert(List L, int pos, int n)
{
    int i;
    List tmp = L, new;
    for(i = 0;i < pos-2; ++i)
        tmp = tmp->Next;
    new = (List)malloc(sizeof(struct Node));
    new->Data = n;
    new->Next = tmp->Next;
    tmp->Next = new;
    return L;
}
List Delete(List L, int pos)
{
    int i;
    if(pos == 1) {
        L = L->Next;
        return L;
    }
    List tmp = L;
    for(i = 0; i < pos-2; ++i) {
        tmp = tmp->Next;
    }
    tmp->Next = tmp->Next->Next;
    return L;
}
int Search(List L, int n) {
    int flag = 0, pos = 0;
    while(L) {
        ++pos;
        if(n == L->Data) {
            flag = 1; break;
        }
        L = L->Next;
    }
    if(flag)
        return pos;
    else return -1;
}
void Output(List L) {
    do {
        printf("%d ", L->Data);
        L = L->Next;
    } while(L);
    printf("\n");
}
List Reverse(List L) {
    List tmp, ans = NULL, list = L;
    while(list) {
        tmp = (List)malloc(sizeof(struct Node));
        tmp->Data = list->Data;
        tmp->Next = ans;
        ans = tmp;
        list = list->Next;
    }
    return ans;
}
List Merge(List a, List b) {
    List ans, Head, tmp = NULL;
    tmp = (List)malloc(sizeof(struct Node));
    Head = tmp;
    while(a&&b) {
        ans = (List)malloc(sizeof(struct Node));
        if(a->Data < b->Data) {
            ans->Data = a->Data;
            a = a->Next;
        }
        else {
            ans->Data = b->Data;
            b = b->Next;
        }
        tmp->Next = ans;
        tmp = tmp->Next;
    }
    while(a) {
        ans = (List)malloc(sizeof(struct Node));
        ans->Data = a->Data;
        a = a->Next;
        tmp->Next = ans;
        tmp = tmp->Next;
    }
    while(b) {
        ans = (List)malloc(sizeof(struct Node));
        ans->Data = b->Data;
        b = b->Next;
        tmp->Next = ans;
        tmp = tmp->Next;
    }
    Head = Head->Next;
    return Head;
}

int main(void)
{
    int N, n, i, pos;
    List list = NULL, tmp = NULL;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &n);
        list = Build(list, n);
    }
    scanf("%d%d", &n, &pos);
    list = Insert(list, pos, n);
    Output(list);
    scanf("%d", &pos);
    list = Delete(list, pos);
    Output(list);
    scanf("%d", &n);
    int ans = Search(list, n);
    if(ans < 0)
        puts("Not found");
    else printf("%d\n", ans);
    list = Reverse(list);
    Output(list);
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &n);
        tmp = Build(tmp, n);
    }
    list = Merge(tmp, list);
    Output(list);
    return 0;
}
