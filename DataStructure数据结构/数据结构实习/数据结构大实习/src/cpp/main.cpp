#include"main.h"
int main()
{
    //1. 创建流
    ifstream input;
    //2. 打开文件，将流与文件相关联
    input.open("testinput.txt");
    //3. 从文件读入数据
    int u=0;
    int n=0;
    int t=0;
    while(1)
    {
        if(input.peek()==EOF) break;
        else
        {
            t=0;
            input >> t;
            //cout<<"t"<<t<<endl;
            n+=t;
            for(int i=0; i<t; i++)
            {
                for(int j=u; j<u+4; j++)
                {
                    input >> number[j];
                }
                u=u+4;
            }
        }
    }

    u=0;
    cout<<"从文件读入的"<<n<<"行数据为："<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=u; j<u+4; j++)
        {
            cout<< number[j]<<" ";
        }
        u=u+4;
        cout<<endl;
    }
    for(int i=0; i<4*n; i++)
    {
        if(number[i]>15||number[i]<=0)
            cout<< number[i]<<"数字不符合要求，请输入不大于15的以空格分隔的非零整数 ";
    }
    cout<<endl;
    u=0;
    for(int i=0; i<n; i++)
    {
        int k=u;
        number[0]=number[k];
        number[1]=number[k+1];
        number[2]=number[k+2];
        number[3]=number[k+3];
        cout<<endl<<"对第"<<i+1<<"行测试样例\t";
        cout<< number[0]<<" ";
        cout<< number[1]<<" ";
        cout<< number[2]<<" ";
        cout<< number[3]<<" ";
        cout<<endl;
        mcount=0;
        for (int i = 0; i < CONT; i++)
        {
            char ch[20];
            //cout<<number[i]<<"  ";
            itoa(number[i],ch, 10);

            biaodashi[i] = ch;
        }

        cout << "中缀表达式"<< "\t"<<"后缀表达式\t"<<"计算结果\t\n";
        Search(CONT,number,biaodashi,&Panduan,&mcount);
        if(Panduan==true)
        {
            cout   << "\n此第"<<i+1<<"组测试数据满足题目的24要求" << endl;
            cout<<"总共的计算方法共有： "<<mcount<<"种"<<endl;
            Panduan = false;
        }
        else
        {
            cout << "此第"<<i+1<<"组测试数据无法满足题目的24要求"   <<   endl;
            Panduan = false;
        }
        u=u+4;
    }
    input.close();
    printf("计算完毕！");
    return 0;
}
