#include<iostream>
using namespace std;

int main(){
    freopen("sample.in","r",stdin);
    int n,target;
    cin >> n >> target;

    if(target==0){
        cout <<0;
        return 0;
    }
    
    int coins[n+1];
    int dp[target+1];// iterate from 1

    for(int i=1;i<=target;i++){
        dp[i]=1e9;
    }

    for(int i=1;i<=n;i++){
        cin >> coins[i];
        dp[coins[i]]=1;
    }

    for(int i=1;i<=target;i++){
        if(dp[i]=1) continue;

        for(int j=1;j<=n;j++){
           if(i-coins[j]>=1) dp[i]=min(dp[i],dp[i-coins[j]]+1);
        }

    }

    cout<<dp[target]<<endl;
    return 0;
}