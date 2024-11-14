#include"InfixToPostfix.h"
int prio(char op)                   //����������ȼ�����
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

bool Trans(string& str1, string& str2)     //���ô���
{
    MyStack s;
    s.Resize(100);                  //����һ��char���͵�ջs
    int i;
    for (i = 0; i < str1.size(); i++)
    {
        if (str1[i] >= '0' && str1[i] <= '9')      //��������֣�ֱ����ջ
        {
            while(str1[i] >= '0' && str1[i] <= '9')
            {
                str2 += str1[i++];
            }
            str2+='#';
            i--;
        }
        else		//����������
        {

            if (s.Empty())            //ջ������վ
                s.Push(str1[i]);
            else if (str1[i] == '(')   //��������ջ
                s.Push(str1[i]);
            else if (str1[i] == ')')    //����������ţ�ֻҪջ�����������ţ��͵��������
            {
                while (s.Top() != '(')
                {
                    str2 += s.Top();
                    s.Pop();
                }
                s.Pop();                 //���������ţ��������
            }
            else  		//��ջ���ǿ�ʱ
            {

                while (prio(str1[i]) <= prio(s.Top()))   //��ջ�����ȼ����ڵ��ڵ�ǰ����������
                {

                    str2 += s.Top();
                    s.Pop();
                    if (s.Empty())      //ջΪ�գ�ֹͣ
                        break;
                }
                s.Push(str1[i]);   //�ѵ�ǰ�������ջ
            }
        }
    }
    while (!s.Empty())        //������ջ���գ��򵯳�����Ԫ�ز����
    {
        str2 += s.Top();
        s.Pop();
    }
    return true;
}

/*

int main()                  //����һ��
{
    string infix;	//�����������׺���ʽ
    string postfix;
    cout << "��������׺���ʽ��" << infix << endl;
    cin >> infix;
    Trans(infix, postfix);
    cout << "��׺���ʽΪ��" << postfix << endl;
    return 0;
}
*/


