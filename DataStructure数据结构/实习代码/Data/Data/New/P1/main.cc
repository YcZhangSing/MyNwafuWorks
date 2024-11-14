#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

template<typename T>
class List {
    private:
        T* a;
        int last;
        int maxSize;
        bool Resize(int sz) {
            T* b = new T[sz];
            if(b == nullptr)
                return false;
            memcpy(b, a, (last+1)*sizeof(int));
            a = b;
            maxSize = sz;
            return true;
        }
    public:
        List<T>(int MaxSize = 0) {
            a = new T[MaxSize];
            last = 0;
            maxSize = MaxSize;
        }
        bool Insert(T x, int loc) {
            if(last == maxSize-1)
                if(!Resize(maxSize+1))
                    return false;
            if(loc <= 0 || loc > last)
                return false;
            for(int i = last+1; i >= loc; --i)
                a[i] = a[i-1];
            a[loc] = x;
            ++last;
            return true;
        }
        bool Remove(int loc) {
            if(loc <= 0 || loc > last)
                return false;
            for(int i = loc; i < last; ++i)
                a[i] = a[i+1];
            --last;
            return true;
        }
        int Search(T x) {
            for(int i = 0; i <= last; ++i) {
                if(a[i] == x)
                    return i+1;
            }
            return 0;
        }
        void Reverse() {
            T* b = new T[maxSize];
            for(int i = 0; i <= last; ++i) {
                b[last-i] = a[i];
            }
            delete[] a;
            a = b;
        }
        List<T>& MergeWith(List<T>& L) {
            int p2new, p2this, p2L;
            p2new = p2this = p2L = 0;
            List<T>* n = new List<T>(maxSize+L.maxSize);
            T* New = n->a;
            while(p2this != last+1 && p2L != L.last+1) {
                if(a[p2this] < L.a[p2L]) {
                    New[p2new++] = a[p2this++];
                }
                else {
                    New[p2new++] = L.a[p2L++];
                }
            }
            while(p2this != last+1) {
                New[p2new++] = a[p2this++];
            }
            while(p2L != L.last+1) {
                New[p2new++] = L.a[p2L++];
            }
            n->last = --p2new;
            return *n;
        }
        friend istream& operator>>(istream& in, List<T>& L) {
            for(int i = 0; i < L.maxSize; ++i) {
                in >> L.a[i];
            }
            L.last = L.maxSize-1;
            return in;
        }
        friend ostream& operator<<(ostream& out, List<T> L) {
            bool flag = false;
            for(int i = 0; i <= L.last; ++i) {
                if(!flag)
                    flag = true;
                else printf(" ");
                out << L.a[i];
            }
            return out;
        }
};
int main(void)
{
    freopen("in.txt", "r", stdin);
    int n, x, i;
    scanf("%d", &n);
    List<int> la(n);
    cin >> la;
    scanf("%d%d", &x, &i);
    la.Insert(x, i);
    cout << la << endl;
    scanf("%d", &i);
    la.Remove(i);
    cout << la << endl;
    scanf("%d", &x);
    i = la.Search(x);
    if(i == 0)
        cout << "Not found" << endl;
    else cout << i << endl;
    scanf("%d", &n);
    la.Reverse();
    cout << la << endl;
    List<int> b(n);
    cin >> b;
    List<int> c = la.MergeWith(b);
    cout << c << endl;
    return 0;
}
