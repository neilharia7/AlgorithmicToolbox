#include<bits/stdc++.h>
using namespace std;
#define long long long
long Max_Pair_Product(const vector<int > v){
	int n = v.size();
	int maxpos = -1,maxpos2 = -1;
	for(int i=0;i<n;i++){
		if((maxpos == -1) || (v[i]>v[maxpos]))
			maxpos = i;
	}
	for(int i=0;i<n;i++){
		if((i!=maxpos) && ((maxpos2 == -1)||(v[i]>v[maxpos2])))
		maxpos2 = i;
	}
	return (long )(v[maxpos])* v[maxpos2];
}
int main(){
	int t;
	cin>>t;
	vector <int > v(t);
	for(int i=0;i<t;i++){
		cin>>v[i];
	}
	unsigned long ans = Max_Pair_Product(v);
	cout<<ans<<endl;
}
