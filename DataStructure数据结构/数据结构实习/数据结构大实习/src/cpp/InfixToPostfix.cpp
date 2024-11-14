#include"InfixToPostfix.h"
int prio(char op)                   //给运算符优先级排序
{
    int priority=0;
    if (op == '*' || op == '/')
        priority = 2;
    if (op == '+' || op == '-')
        priority = 1;
    if (op == '(')
        priority = 0;
    return priority;
}

bool Trans(string& str1, string& str2)     //引用传递
{
    MyStack s;
    s.Resize(100);                  //定义一个char类型的栈s
    int i;
    for (i = 0; i < str1.size(); i++)
    {
        if (str1[i] >= '0' && str1[i] <= '9')      //如果是数字，直接入栈
        {
            while(str1[i] >= '0' && str1[i] <= '9')
            {
                str2 += str1[i++];
            }
            str2+='#';
            i--;
        }
        else		//否则不是数字
        {

            if (s.Empty())            //栈空则入站
                s.Push(str1[i]);
            else if (str1[i] == '(')   //左括号入栈
                s.Push(str1[i]);
            else if (str1[i] == ')')    //如果是右括号，只要栈顶不是左括号，就弹出并输出
            {
                while (s.Top() != '(')
                {
                    str2 += s.Top();
                    s.Pop();
                }
                s.Pop();                 //弹出左括号，但不输出
            }
            else  		//当栈顶非空时
            {

                while (prio(str1[i]) <= prio(s.Top()))   //当栈顶优先级大于等于当前运算符，输出
                {

                    str2 += s.Top();
                    s.Pop();
                    if (s.Empty())      //栈为空，停止
                        break;
                }
                s.Push(str1[i]);   //把当前运算符入栈
            }
        }
    }
    while (!s.Empty())        //最后，如果栈不空，则弹出所有元素并输出
    {
        str2 += s.Top();
        s.Pop();
    }
    return true;
}

/*

int main()                  //测试一下
{
    string infix;	//保存输入的中缀表达式
    string postfix;
    cout << "请输入中缀表达式：" << infix << endl;
    cin >> infix;
    Trans(infix, postfix);
    cout << "后缀表达式为：" << postfix << endl;
    return 0;
}
*/


