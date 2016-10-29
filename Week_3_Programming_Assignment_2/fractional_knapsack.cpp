#include<bits/stdc++.h>
using namespace std;
int main(){
    double n,capacity,value[1000],weight[1000],ratio[1000],swap,sum=0;
    int index =-1;
    cin>>n>>capacity;
    for(int i=0;i<n;i++){
        cin>>value[i]>>weight[i];
        ratio[i] = value[i]/weight[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(ratio[j]>ratio[j+1]){
                swap = ratio[j];
                ratio[j] = ratio[j+1];
                ratio[j+1] = swap;
                
                swap = value[j];
                value[j] = value[j + 1];
                value[j + 1] = swap;

                swap = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = swap;
            }
        }
    }
	for(int i=n-1;i>=0;i--){
        if(capacity-weight[i]<0){
            index=i;
            break;
        }
        capacity-=weight[i];
        sum+=value[i];
    }
    if(index != -1)
        sum +=capacity*ratio[index];
    cout<<setprecision(4)<<fixed<<sum<<endl;
    return 0;
}
