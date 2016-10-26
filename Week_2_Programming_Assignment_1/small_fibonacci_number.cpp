#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,sum=0;
	cin>>n;
	int a = 0,b=1,c;
	if(n<=1){
		cout<<n<<endl;
	}
	else{
	    for(int i=1;i<n;i++){
	        sum = a+b;
	        a = b;b = sum;
	    }
	    cout<<sum<<endl;
	}
	return 0;
}
