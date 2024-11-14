#include"calpostfix.h"
int calsufix(string tokens)
{
    MyStack numbers;
    numbers.Resize(128);

    for(int i = 0 ; i < tokens.size() ; i++)
    {
        //��Ϊ��������򵯳�����ջ��Ԫ�أ��������㲢������Ż�ջ
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
int main()//����һ��
{
    int x = calsufix("3639/+*");
    cout<<"x�ǣ�"<<x<<endl;
}
*/



