#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,flag=0;
    cin>>n;
    map<int,int > a;
    map<int, int > :: iterator m;
    for(int i=0; i<n; i++){
        cin>>k;
        a[k]++;
    }
    for(m = a.begin(); m!= a.end(); m++){
        if(m->second > n/2){
            flag=1;
            break;
        } 
    }
    cout<<flag<<endl;
    return 0;
}
