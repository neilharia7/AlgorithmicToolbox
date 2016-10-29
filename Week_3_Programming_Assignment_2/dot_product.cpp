#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long a[1000],b[1000]; // given a is profits per click, b is average number of clicks
    unsigned long long maxrevenue = 0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    for(int i=0;i<n;i++){
        maxrevenue +=a[i]*b[i];
    }
    cout<<maxrevenue<<endl;
    return 0;
}
