/*
Task. Given an integer n, compute the minimum number of operations needed to obtain the number n
starting from the number 1.

Input Format. The input consists of a single integer 1 <= n <= 1000000.

Output Format. In the first line, output the minimum number k of operations needed to get n from 1.
In the second line output a sequence of intermediate numbers. That is, the second line should contain
positive integers a0; a2; : : : ; ak􀀀1 such that a0 = 1, ak􀀀1 = n and for all 0 <= i < k 􀀀 1, ai+1 is equal to
either ai + 1, 2ai, or 3ai. If there are many such sequences, output any one of them.
*/

#include <bits/stdc++.h>
using namespace std;
vector<int > optimal_sequence(int n){
    vector<int > sequence;
    if (n==0) {
        sequence.push_back(0);
        return sequence;
    }else if(n==1){
        sequence.push_back(1);
        return sequence;
    }
    vector<int > m(n+1,0);
    m[0] = 0;
    for (int i = 1;i<n+1;i++){
        m[i] = m[i-1]+1;
        if (i%2==0){
            if (i/2==1){
                m[i] = 1;
            }else{
                m[i] = min(m[i/2]+1, m[i]);
            }
        }
        if (i%3==0){
            if (i/3==1){
                m[i] = 1;
            }else{
                m[i] = min(m[i/3]+1, m[i]);
            }
        }
    }
    while (n > 0){
        sequence.push_back(n);
        if (n==2 || n==3){
            sequence.push_back(1);
            break;
        }
        if (m[n]== m[n-1]+1) {
            n = n - 1;
        }
        else if (n % 2 == 0 && m[n]==m[n/2]+1) {
            n = n/2;
        }
        else if (n % 3 == 0 && m[n]==m[n/3]+1) {
            n = n/3;
        }
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}
int main(){
    int n;
    cin >> n;
    vector<int> sequence = optimal_sequence(n);
    cout <<sequence.size()-1<<endl;
    for (int i = 0; i < sequence.size();i++) {
        cout<<sequence[i]<<" ";
    }
}
