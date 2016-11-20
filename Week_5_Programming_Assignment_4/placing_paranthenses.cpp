#include <bits/stdc++.h>
using namespace std;
#define long long long
long eval(long a, long b, char op) {
    if (op == '*'){
        return a * b;
    }
	else if (op == '+'){
        return a + b;
    }
	else if (op == '-'){
        return a - b;
    }
	else {
        assert(0);
    }
}
long get_maximum_value(const string &exp) {
    vector<long >numbers;
    vector<char >op;
    for (int i = 0; i <  exp.size(); i++){
        if (i%2==0){
            numbers.push_back((long ) exp[i] - 48);
        }
		else{
            op.push_back(exp[i]);
        }
    }
    vector<vector<long > >M(numbers.size());
    vector<vector<long > >m(numbers.size());
    for (int i=0; i< numbers.size(); i++){
        M[i].resize(numbers.size());
        m[i].resize(numbers.size());
    }
    for (int i = 0; i < numbers.size(); ++i) {
        for (int j = 0; j < numbers.size(); ++j) {
            if (i==j){
                M[i][j] = numbers[i];
                m[i][j] = numbers[i];
            }
        }
    }
    for (int s=1; s < numbers.size(); s++){
        for (int i=0; i < numbers.size()-s; i++){
            int j = i+s;
            long max_value = numeric_limits<long>::min();
            long min_value = numeric_limits<long>::max();
            for (int k = i; k <=  j-1; k++){
                long a = eval(M[i][k], M[k+1][j], op[k]);
                long b = eval(M[i][k], m[k+1][j], op[k]);
                long c = eval(m[i][k], M[k+1][j], op[k]);
                long d = eval(m[i][k], m[k+1][j], op[k]);
                max_value = max(max_value,max(a, max(b, max(c, d))));
                min_value = min(min_value,min(a, min(b, min(c, d))));
            }
            pair<long, long>min_max;
            min_max.first = min_value;
            min_max.second = max_value;
            m[i][j] = min_max.first;
            M[i][j] = min_max.second;
        }
    }
    return M[0][numbers.size()-1];
}
int main(){
    string s;
    cin>>s;
    cout << get_maximum_value(s) <<endl;
    return 0;
}
