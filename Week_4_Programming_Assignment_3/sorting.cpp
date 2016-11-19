/*
Task. To force the given implementation of the quick sort algorithm to efficiently process sequences with
few unique elements, your goal is replace a 2-way partition with a 3-way partition. That is, your new
partition procedure should partition the array into three parts: < x part, = x part, and > x part.

Input Format. The first line of the input contains an integer n. The next line contains a sequence of n
integers a0; a1; : : : ; an􀀀1.

Constraints. 1 <= n < 100001; 1 <= ai < 1000000001 for all 0 <= i < n.

Output Format. Output this sequence sorted in non-decreasing order.
*/

#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void partition(int a[], int low, int high, int &i, int &j){
    if (high - low <= 1){
        if (a[high] < a[low])
            swap(&a[high], &a[low]);
        i = low;
        j = high;
        return;
    }
    int mid = low;
    int pivot = a[high];
    while (mid <= high){
        if (a[mid] < pivot)
            swap(&a[low++], &a[mid++]);
        else if (a[mid] == pivot)
            mid++;
        else if (a[mid] > pivot)
            swap(&a[mid], &a[high--]);
    }
    i = low-1;
    j = mid;
}
void quicksort(int a[], int low, int high){
    if (low>=high)
        return;
    int i, j;
    partition(a, low, high, i, j);
    quicksort(a, low, i);
    quicksort(a, j, high);
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    quicksort(a, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
