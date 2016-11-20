#include<bits/stdc++.h>
using namespace std;
int editDistance(string s1,string s2){
    int eDist[101][101];
    for(int i=0;i <= s2.size();i++){ 
        eDist[0][i] = i; 
    }
    for(int i=0;i <= s1.size();i++){
        eDist[i][0] = i;
    }
    int a = s1.size();
    int b = s2.size();
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(s1[i-1] == s2[j-1])
                eDist[i][j] = eDist[i-1][j-1];
            else
                eDist[i][j] = 1 + fmin( eDist[i][j-1] , fmin(eDist[i-1][j] , eDist[i-1][j-1]));
        }
    }
    return eDist[s1.size()][s2.size()];
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<editDistance(s1,s2)<<endl;
    return 0;
}
