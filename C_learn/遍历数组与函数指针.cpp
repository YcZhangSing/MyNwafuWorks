#include <stdio.h>
#include <stdlib.h>

#define N 10

//����ԭ��
// �������
void Traversal(int [], int, void (*pf)(int *));
// ���ܺ���
void Input(int *);
void Output(int *);
void Set2Zero(int *);
void PowOdd(int *);

int main()
{
    int iArray[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    Traversal(iArray, N, Output);
    printf("\n");
    
    Traversal(iArray, N, Set2Zero);
    
    Traversal(iArray, N, Output);
    printf("\n");
    
    Traversal(iArray, N, Input);
    
    Traversal(iArray, N, Output);
    
    printf("\n");
    Traversal(iArray, N, PowOdd);
    
    Traversal(iArray, N, Output);
    
    printf("\n");


    return 0;
}

// ��������
// ��������
void Traversal(int a[], int n, void (*pf)(int *))
{
    int i;

    // ��������
    for(i = 0; i < n; i++)
    {
        pf(&a[i]); // ���ô���ĺ���
    }
}

// ��������
void Input(int * pData)
{
    scanf("%d", pData);
}
// �������
void Output(int * pData)
{
    // ���
    printf("%d ", *pData);
}

// ��0
void Set2Zero(int * pData)
{
    *pData = 0; // ��0
}

// ����Ԫ����ƽ��
void PowOdd(int * pData)
{
    if(*pData % 2 != 0)
    {
        *pData *= *pData;
    }
}

