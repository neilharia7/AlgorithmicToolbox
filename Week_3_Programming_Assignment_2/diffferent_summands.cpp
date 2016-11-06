#include<bits/stdc++.h>
using namespace std;
vector<int > optimal_summands(int n) {
    vector<int> summands;
    int a=n;
    int b=1;
    if (a <= 2*b)
        summands.push_back(n);
    else{
        while (a>2*b) {
            summands.push_back(b);
            a-=b;
            b++;
        }
        summands.push_back(a);
    }
    return summands;
}
int main() {
    int n;
    cin>>n;
    vector<int > summands = optimal_summands(n);
    cout<<summands.size()<<endl;
    for (int i=0;i<summands.size();i++) {
        cout<<summands[i]<<' ';
    }
    return 0;
}
