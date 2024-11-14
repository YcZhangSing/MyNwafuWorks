#include"search.h"
void Search(int n,int * number,string* biaodashi,bool* panduan,int* mcount)
{
    if (n == 1)
    {
        if ( number[0] - VALUE == 0   )//可以算出24,输出表达式
        {

            cout << biaodashi[0] << "\t";
            yanzheng(biaodashi[0]);//中缀转后缀并计算验证
            *panduan = true;
            (*mcount)++;
            if(((*mcount) % 3)==0)

                cout<<endl;
        }
    }

    for(int i=0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int  a, b;
            string  expa, expb;
            a = number[i];
            b = number[j];
            number[j] = number[n - 1];
            expa = biaodashi[i];
            expb = biaodashi[j];
            biaodashi[j] = biaodashi[n - 1];

            //+
            biaodashi[i]= '('+ expa + '+' + expb + ')';
            number[i] = a + b;
            Search(n-1,number,biaodashi,panduan,mcount);
            //-
            biaodashi[i]='('+ expa+ '-' + expb + ')';
            number[i] = a - b;
            Search(n-1,number,biaodashi,panduan,mcount);
            //*
            biaodashi[i] = '('+expb + '-' + expa + ')';
            number[i] = b -a;
            Search(n-1,number,biaodashi,panduan,mcount);
            //除法
            biaodashi[i]= '('+ expa +'*'+ expb+ ')';
            number[i]=a*b;
            Search(n-1,number,biaodashi,panduan,mcount);
                //分情况判断
            if (b != 0)
            {
                biaodashi[i] ='('+expa+'/' + expb + ')';
                number[i] = a / b;
                Search(n-1,number,biaodashi,panduan,mcount);
            }
            if (a != 0)
            {
                biaodashi[i]='('+expb + '/'+ expa + ')';
                number[i] = b / a;
                Search(n-1,number,biaodashi,panduan,mcount);
            }

            number[i] =a;
            number[j]=b;
            biaodashi[i] = expa;
            biaodashi[j] = expb;
        }
    }
}
