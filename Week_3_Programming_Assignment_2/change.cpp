/* The goal in this problem is to find the minimum number of coins needed to change the input value
(an integer) into coins with denominations 1, 5, and 10. */
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
