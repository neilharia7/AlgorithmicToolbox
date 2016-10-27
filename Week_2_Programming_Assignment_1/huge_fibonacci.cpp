#include <bits/stdc++.h>
using namespace std;
#define long long long
map<long, long> M;
long fibo(long n,long mod){
    unsigned long k=n/2;
	if (M.count(n)){ 
	    return M[n];
	}
	if(n%2==0){
		return M[n] = (fibo(k,mod)*fibo(k,mod) + fibo(k-1,mod)*fibo(k-1,mod)) % mod;
	}
	else{
		return M[n] = (fibo(k,mod)*fibo(k+1,mod) + fibo(k-1,mod)*fibo(k,mod)) % mod;
	}
}
int main(){
	unsigned long n,mod;
	M[0]=M[1]=1;
	cin>>n>>mod;
	cout<<(n==0 ? 0 : fibo(n-1,mod))<<endl;
}
