#include <iostream>

using namespace std;

void merge(int s, int mid, int e, int tmp[], int a[])
{
    int p1 = s;
    int p2 = mid+1;
    int p = 0;
    while(p1 <= mid && p2 <= e) {
        if(a[p1] < a[p2]) tmp[p++] = a[p1++];
        else tmp[p++] = a[p2++];
    }
    while(p1 <= mid) tmp[p++] = a[p1++];
    while(p2 <= e) tmp[p++] = a[p2++];
    p = 0;
    for(int i = s; i <= e; i++) {
        a[i] = tmp[p++];
    }
}
void mergeSort(int s, int e, int tmp[], int a[])
{
    if(s < e) {
        int mid = s+(e-s)/2;
        mergeSort(s, mid, tmp, a);
        mergeSort(mid+1, e, tmp, a);
        merge(s, mid, e, tmp, a);
    }
}
int main(void)
{
    int lenth; cin >> lenth;
    int a[lenth], tmp[lenth];
    for(int i = 0; i < lenth; i++) {
        cin >> a[i];
    }
    mergeSort(0, lenth-1, tmp, a);
    for(int i = 0; i < lenth; i++) {
        cout << a[i] << "\n";
    }
    return 0;
}
