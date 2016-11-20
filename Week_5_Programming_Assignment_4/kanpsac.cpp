#include <bits/stdc++.h>
using namespace std;
int knapsack[300][10000];
int goldbars[300];
int main(){
    int capacity, n;
    cin>>capacity>>n;
	  n+=1;
	  capacity+=1;
    goldbars[0] = 0;
    for(int i = 1; i < n; i++){
        cin >> goldbars[i];
    }
    sort(goldbars, goldbars + n);
    for(int i = 0; i < capacity; i++){
        knapsack[0][i] = 0;
    }
    for(int i = 0; i < n; i++){
        knapsack[i][0] = 0;
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < capacity; j++){
            if(j < goldbars[i]){
                knapsack[i][j] = knapsack[i - 1][j];
            }
            else{
                knapsack[i][j] = fmax(knapsack[i - 1][j], goldbars[i] + knapsack[i - 1][j - goldbars[i]]);
            }
        }
    }
    cout << knapsack[n - 1][capacity - 1];
    return 0;
}
