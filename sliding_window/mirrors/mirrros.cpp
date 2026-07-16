#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
    freopen("mirrors.in", "r", stdin);
    int n;
    cin >> n;

    vector<ll> b(n);
    for(int i=0;i<n;i++) cin >> b[i];

    vector<ll> prefix(n);
    prefix[0]=b[0];
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+b[i];
    }

    ll ans=LLONG_MIN;
    for(int s=0;s<=n;s++){
        ll left_sum,right_sum;
        if(s==0){
            left_sum=0;
            right_sum=prefix[n-1];
        }else if(s==n){
            left_sum=prefix[n-1];
            right_sum=0;
        }else{
            left_sum=prefix[s-1];
            right_sum=prefix[n-1]-prefix[s-1];
        }

        if(left_sum<=right_sum){
            ll target=left_sum+1;
            auto it=upper_bound(prefix.begin()+s,prefix.end(),prefix[s-1]+target);
            ll k=(long long)(it-prefix.begin())-1;
            ans=max(ans,k);
        }else if(left_sum>right_sum){
            ll target=right_sum+1;

            auto it=upper_bound(prefix.begin(),prefix.begin()+s,prefix[s]-target);
            ll k=(long long)(prefix.end()-it);
            ans=max(ans,k);
        }
    }
}