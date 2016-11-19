#include <bits/stdc++.h>
using namespace std;
#define long long long
long inversions = 0;
void Merge(int left[], int right[], int a[], int left_part, int right_part){
    int i=0,j=0,k=0;
    while((i < left_part) && (j < right_part)){
        if(left[i] <= right[j]){
            a[k++] = left[i++]; 
        }
        else{
            a[k++] = right[j++];
            inversions += (left_part - i);
        }
    }
    while(i < left_part){
        a[k++] = left[i++];
    }
    while(j < right_part){
        a[k++] = right[j++];
    }
}
void MSort(int a[], int n){
    if(n < 2)
        return;
    else{
        int mid = n/2;
        int left[mid];
        int right[n - mid];
        for(int i = 0; i < mid; i++){
            left[i] = a[i];
        }
        for(int i = mid; i < n; i++){
            right[i - mid] = a[i];
        }
        MSort(left, mid);
        MSort(right, n - mid);
        Merge(left, right, a, mid, n - mid);
    }
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    MSort(a, n);
    cout<<inversions<<endl;
    return 0;
}
