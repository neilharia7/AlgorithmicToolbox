#include <bits/stdc++.h>
using namespace std;
#define long long long
int main(){
    long n, ans = 0;
    int arr[60],sum = 1;
    cin>>n;
    arr[0] = 0;arr[1] = 1;
    if(n<=1)
        cout<<n;
    else{  //Pisano periods for F(mod 10) is 60. refer to https://en.wikipedia.org/wiki/Pisano_period
        for(int i = 2; i < 60; i++){
            arr[i] = (arr[i-1] + arr[i-2])%10;
            sum += arr[i];
        }  // Since period occurs every (n / 60) no. of times
        ans += (((n / 60)*(sum % 10)))%10; 
        if(((n % 60) == 0)||((n % 60) == 1)){
            ans +=n % 60;
        }
        else{
            ans += 1;
            for(int i = 2; i <= (n % 60); i++){ 
                ans += arr[i];
            }
        }
        cout<<ans % 10<<endl; 
    }
    return 0;
}
