#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int Number;
    char Name[256];
    double Score[3];
    double Average;
    struct Node* Next;
}* Student;

Student Insert(Student stu)
{
    int i;
    Student cur = stu, pre;
    Student tmp = (Student)malloc(sizeof(struct Node));
    scanf("%d %s", &tmp->Number, tmp->Name);
    for(i = 0; i < 3; ++i)
        scanf("%lf", &tmp->Score[i]);
    tmp->Average = (tmp->Score[0]+tmp->Score[1]+tmp->Score[2])/3;
    pre = cur;
    while(cur && cur->Average > tmp->Average) {
        pre = cur;
        cur = cur->Next;
    }
    tmp->Next = pre->Next;
    pre->Next = tmp;
    return stu;
}
void OutPut(Student stu) {
    stu = stu->Next;
    int cnt = 0, i;
    while(stu) {
        printf("%d %s ", stu->Number, stu->Name);
        for(i = 0; i < 3; ++i)
            printf("%.2lf ", stu->Score[i]);
        printf("%.2lf %d\n", stu->Average, ++cnt);
        stu = stu->Next;
    }
}

int main(void)
{
    Student stu = (Student)malloc(sizeof(struct Node));
    int N, i;
    stu->Average = 1<<30;
    stu->Next = NULL;
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
        stu = Insert(stu);
    OutPut(stu);
    return 0;
}
