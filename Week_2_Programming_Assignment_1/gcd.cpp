#include <bits/stdc++.h>
using namespace std;
long gcd(long a,long b){
    return b == 0 ? a : gcd(b, a % b);
}
int main(){
	long a,b;
	cin>>a>>b;
	cout<<gcd(a,b)<<endl;
	return 0;
}
