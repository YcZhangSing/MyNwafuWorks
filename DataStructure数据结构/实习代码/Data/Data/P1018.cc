#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int N;
    struct Node* Next,*Pre;
}*Person;

int main(void)
{
    int M, N, i;
    scanf("%d%d", &M, &N);
    /* printf("%d %d\n", M, N); */
    Person head = (Person)malloc(sizeof(struct Node));
    head->N = 1;
    head->Next = head->Pre = NULL;
    Person cur = head;
    for(i = 2; i <= 2*M; ++i) {
        cur->Next = (Person)malloc(sizeof(struct Node));
        cur->Next->N = i;
        cur->Next->Pre = cur;
        cur = cur->Next;
    }
    cur->Next = head;
    head->Pre = cur;

    Person tmp = head;
    int dir = 0;
    while(dir != 2*M-1) {
        if(dir < M) {
            for(i = 1; i < N; ++i)
                tmp = tmp->Next;
            tmp->Next->Pre = tmp->Pre;
            tmp->Pre->Next = tmp->Next;
            ++dir;
            /* printf("%d ", tmp->N); */
            if(dir == M)
                tmp = tmp->Pre;
            else tmp = tmp->Next;
        } else {
            for(i = 1; i < N; ++i)
                tmp = tmp->Pre;
            tmp->Pre->Next = tmp->Next;
            tmp->Next->Pre = tmp->Pre;
            ++dir;
            /* printf("%d ", tmp->N); */
            tmp = tmp->Pre;
        }
    }
    printf("%d\n", tmp->N);
    return 0;
}

