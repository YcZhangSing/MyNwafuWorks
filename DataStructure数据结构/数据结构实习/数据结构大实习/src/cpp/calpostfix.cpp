#include"calpostfix.h"
int calsufix(string tokens)
{
    MyStack numbers;
    numbers.Resize(128);

    for(int i = 0 ; i < tokens.size() ; i++)
    {
        //若为运算符，则弹出两个栈顶元素，进行运算并将结果放回栈
        if(tokens[i] == '+' || tokens[i] == '-' || tokens[i] == '*' || tokens[i] == '/')
        {
            int res;
            int n2 = (int)numbers.Top();
            numbers.Pop();
            int n1 = (int)numbers.Top();
            numbers.Pop();

            if(tokens[i] == '+')
                res = n1 + n2;
            else if(tokens[i] == '-')
                res = n1 - n2;
            else if(tokens[i] == '/')
                res = n1 / n2;
            else
                res = n1 * n2;
            numbers.Push(res);
        }
        else if(tokens[i] == '#')
        {
            continue;
        }
        else
        {
            int temp = 0;
            while(tokens[i] >= '0' && tokens[i] <= '9')
            {
                temp = temp *10 + int(tokens[i] - '0');
                i++;
            }
            numbers.Push(temp);
        }
    }
    return numbers.Top();
}

/*
int main()//测试一下
{
    int x = calsufix("3639/+*");
    cout<<"x是："<<x<<endl;
}
*/



