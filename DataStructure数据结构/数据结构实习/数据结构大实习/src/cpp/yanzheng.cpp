#include"yanzheng.h"
void yanzheng(string infix)
{
    string sufix="";
    Trans(infix, sufix);
    int res = calsufix(sufix);
    cout<<sufix<<"\t"<<res<<"\t\n";
}
