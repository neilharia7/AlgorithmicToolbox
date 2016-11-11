#include<bits/stdc++.h>
using namespace std;
int BSearch(int a[], int low, int high, int x){
    if(low > high)
        return -1;
    int middle = (high+low)/2;
    if(a[middle] == x){
        return middle;
    }
    else if(x < a[middle]){
        return BSearch(a, low, middle-1, x);
    }
    else{
        return BSearch(a, middle+1, high, x);
    }
}
int main(){
    int n,a[100000],k,search_key;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>k; // number of searches
    while(k--){
        cin>>search_key;
        cout<<BSearch(a,0,n-1,search_key)<<" ";
    }
}
