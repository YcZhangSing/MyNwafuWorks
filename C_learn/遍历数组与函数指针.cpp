#include <stdio.h>
#include <stdlib.h>

#define N 10

//函数原型
// 数组遍历
void Traversal(int [], int, void (*pf)(int *));
// 功能函数
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

// 函数定义
// 遍历数组
void Traversal(int a[], int n, void (*pf)(int *))
{
    int i;

    // 遍历数组
    for(i = 0; i < n; i++)
    {
        pf(&a[i]); // 调用传入的函数
    }
}

// 输入数据
void Input(int * pData)
{
    scanf("%d", pData);
}
// 输出数据
void Output(int * pData)
{
    // 输出
    printf("%d ", *pData);
}

// 清0
void Set2Zero(int * pData)
{
    *pData = 0; // 清0
}

// 奇数元素求平方
void PowOdd(int * pData)
{
    if(*pData % 2 != 0)
    {
        *pData *= *pData;
    }
}

