#include"main.h"
int main()
{
    //1. ������
    ifstream input;
    //2. ���ļ����������ļ������
    input.open("testinput.txt");
    //3. ���ļ���������
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
    cout<<"���ļ������"<<n<<"������Ϊ��"<<endl;
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
            cout<< number[i]<<"���ֲ�����Ҫ�������벻����15���Կո�ָ��ķ������� ";
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
        cout<<endl<<"�Ե�"<<i+1<<"�в�������\t";
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

        cout << "��׺���ʽ"<< "\t"<<"��׺���ʽ\t"<<"������\t\n";
        Search(CONT,number,biaodashi,&Panduan,&mcount);
        if(Panduan==true)
        {
            cout   << "\n�˵�"<<i+1<<"���������������Ŀ��24Ҫ��" << endl;
            cout<<"�ܹ��ļ��㷽�����У� "<<mcount<<"��"<<endl;
            Panduan = false;
        }
        else
        {
            cout << "�˵�"<<i+1<<"����������޷�������Ŀ��24Ҫ��"   <<   endl;
            Panduan = false;
        }
        u=u+4;
    }
    input.close();
    printf("������ϣ�");
    return 0;
}
