#include<bits/stdc++.h>
using namespace std;
int main(){
    int amount;
    cin>>amount;
    int remaining = amount % 10;
    int count = amount/10 + remaining/5 + remaining%5;
    cout<<count<<endl;
    return 0;
}
