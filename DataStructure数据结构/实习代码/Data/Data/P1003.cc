#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void quickSort(int a[], int s, int e)
{
    if(s >= e) return;
    int k = a[s];
    int i = s, j = e;
    while( i!= j) {
        while(j > i && a[j] >= k)
            j--;
        swap(a[i], a[j]);
        while(i < j && a[i] <= k)
            i++;
        swap(a[i], a[j]);
    }
    quickSort(a, s, i-1);
    quickSort(a, i+1, e);
}
int main(void)
{
    int lenth;
    cin >> lenth;
    int a[lenth];
    for(int i = 0; i < lenth; i++)
        cin >> a[i];
    quickSort(a, 0, lenth-1);
    for(int i = 0; i < lenth; i++)
        cout << a[i] << endl;
    return 0;
}
