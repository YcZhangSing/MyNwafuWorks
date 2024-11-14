#include <iostream>
using namespace std;
int main()
{
    int && a = 100;            
    int b = 200;    
    int && c = a+b;             
    int && d = 300;           
    a += 10;                    
    int e = a;                
    cout<<"a = "<<a<<", b = "<<b<<", c = "<<c<<", d = "<<d<<", e = "<<e<<endl;
    return 0;
}

