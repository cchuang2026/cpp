#include<iostream>
using namespace std;

int main(){
    freopen("sample.in","r",stdin);

    int n,target;
    cin >> n >> target;

    vector<int> coins(n+1);
   vector<int> dp(target+1,0);
    for(int i=1;i<=n;i++){
        cin >> coins[i];
        dp[coins[i]]=1;
    }

    sort(coins.begin(),coins.end());

    for(int i=1;i<=target;i++){

        for(int j=1;j<=n;j++){

            if(i-coins[j]>=1){
                int index_check=i-coins[j];
                dp[i]+=dp[index_check];
            }

        }
        
    }

    cout<<dp[target]<<endl;
}