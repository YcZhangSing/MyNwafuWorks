#include<iostream>


const int MaxSize = 100;
using namespace std;
template<class T>
class SeqList{
    private:
        void resize(int x){
            T *b;
            if(x>maxSize){
                b=new T[x];
            }
            for(int i=0;i<=last;i++){
                b[i]=a[i];
            }
            maxSize = x;
            delete []a;
            a = b;
        }

    public:
        T *a;
        int maxSize;
        int last;    //0 start
        SeqList(int sz = MaxSize) {
            a=new T[sz];
            maxSize = sz;
            last = -1;
        }
        ~SeqList(){
            delete[] a;
        }
        int Size()const{
            return last+1;
        }
        int Search(T& x)const{
            for(int t=0;t<last+1;t++){
                if(a[t]==x){
                    return t+1;
                }
            }
            return -1;
        }
        /* bool Remove(T& x){ */
        /*     if(last== -1){ */
        /*         return false; */
        /*     } */
        /*     for(int i=0;i<last+1;i++){ */
        /*         if(a[i]==x){ */
        /*             for(;i<=last;i++){ */
        /*                 a[i]=a[i+1]; */
        /*             } */
        /*             return true' */
        /*         }else{ */
        /*             return false; */
        /*         } */
        /*     } */
        /*     return true; */
        /* } */
        bool Insert(int i,T& x){
            int y=maxSize+1;
            resize(y);
            if(last == maxSize-1){
                return false;
            }
            if(i<0||i>last+1){
                return false;
            }
            for(int j = last;j > i-2;j--){
                a[j+1]=a[j];
            }
            a[i-1] = x;
            last++;
            return true;
        }
        bool Delete(int i){
            if(i<0||i>last+1){
                return false;
            }
            for(int j=i-1;j<last+1;j++){
                a[j]=a[j+1];
            }
            last--;
            return true;
        }


        int Length()const{
            return last+1;
        }
        void reverse(){
            T temp;
            for(int i=0,j=last;i!=j;i++,j--){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        SeqList<T>* add(SeqList<T>& L ){
            int cur2this = 0, cur2L = 0, cur2new = 0;
            SeqList<T>* c = new SeqList<T>(last+L.last);
            while(cur2this != last+1 && cur2L != L.last+1) {
                if(a[cur2this] < L.a[cur2L]) {
                    c->a[cur2new] = a[cur2this];
                    cur2this++;
                }
                else {
                    c->a[cur2new] = L.a[cur2L];
                    cur2L++;
                }
                ++cur2new;
            }
            while(cur2this != last+1) {
                c->a[cur2new++] = a[cur2this++];
            }
            while(cur2L != L.last+1)
                c->a[cur2new++] = L.a[cur2L++];
            c->last = --cur2new;
            return c;
            /* SeqList<T> *c=new SeqList<T>(last+L.last); */
            /* int t=1; */
            /* for(i=0;i<=last;i++){ */
            /*     for(j=0;j<=L.last;j++){ */
            /*         if(L.a[j]<a[i]){ */
            /*             c->Insert(t,L.a[j]); */
            /*             t++; */
            /*         } */
            /*         else{ */
            /*             c->Insert(t,L.a[i]); */
            /*             t++; */
            /*         } */
            /*     } */
            /* } */
            /* if(i==last+1){ */
            /*     for(j=j+1;j<=L.last;j++){ */
            /*         c->Insert(t,L.a[j]); */
            /*         t++; */
            /*     } */
            /*     return c; */
            /* } */
            /* else{ */
            /*     for(i=i+1;i<=last;i++){ */
            /*         c->Insert(t,a[i]); */
            /*         t++; */
            /*     } */
            /*     return c; */
            /* } */
        }
};



int main(void)
{
    freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    SeqList<int> la(n);
    for(int i = 0; i < la.maxSize; ++i) {
        cin >> la.a[i];
        ++la.last;
    }
    /* cout << "After Init" << endl; */
    /* for(int i=0;i<=la.last;i++){ */
    /*     cout << la.a[i] << " "; */
    /* } */
    /* cout << endl; */
    int x, i;
    cin >> x >> i;
    la.Insert(i,x);
    /* cout << "After Insert" << endl; */
    for(int i=0;i<=la.last;i++){
        cout << la.a[i] << " ";
    }
    cout << endl;
    int l;
    cin >> l;
    la.Delete(l);
    /* cout << "After Delete" << endl; */
    for(int i=0;i<=la.last;i++){
        cout << la.a[i] <<" ";
    }
    cout << endl;
    int y;
    cin >> y;
    /* cout << "After Search" << endl; */
    if(la.Search(y)!=-1){
        int x=la.Search(y);
        cout << x  << endl;
    }
    else{
        cout << "Not Found"<<endl;
    }
    la.reverse();
    for(int i=0;i<=la.last;i++){
        cout << la.a[i]<<" ";
    }
    int m;
    cin >> m;
    SeqList<int> lb(m);
    for(int i=0;i<lb.maxSize;i++){
        cin >> lb.a[i];
        ++lb.last;
    }
    cout << endl;
    SeqList<int>* c=la.add(lb);
    for(int i=0;i<=c->last;i++){
        cout << c->a[i] << " ";
    }
    return 0;
}
