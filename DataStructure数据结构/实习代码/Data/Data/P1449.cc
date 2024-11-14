#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char Name[16], Num[11], Gender[6], Class[11], Health[20] ,Age[3];
    struct Node* Next;
}* Stack;

Stack Insert(Stack S) {
    Stack NS;
    if( !S ) {
        NS = (Stack)malloc(sizeof(struct Node));
        NS->Next = NULL;
    } else {
        NS = (Stack)malloc(sizeof(struct Node));
        NS->Next = S;
    }
    scanf(" %s%s%s%s%s%s", NS->Name, NS->Num, NS->Gender, NS->Age, NS->Class, NS->Health);
    return NS;
}
void OutPut(Stack S) {
    while(S) {
        printf("%s %s %s %s %s %s\n", S->Name, S->Num, S->Gender, S->Age, S->Class, S->Health);
        S = S->Next;
    }
}
int main(void)
{
    int N, i;
    Stack S = NULL;
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
        S = Insert(S);
    OutPut(S);
    return 0;
}
