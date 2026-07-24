#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
    freopen("mirrors.in", "r", stdin);
    int n;
    cin >> n;

    vector<ll> b(n+1);
    for(int i=1;i<=n;i++) cin >> b[i];

    vector<ll> prefix(n+1,0);

    for(int i=1;i<=n;i++){
        prefix[i]=prefix[i-1]+b[i];
    }

    ll ans=LLONG_MIN;
    for(int s=0;s<=n;s++){
        ll left_sum,right_sum;
        left_sum=prefix[s];
        right_sum=prefix[n]-prefix[s];

        if(left_sum<=right_sum){
            ll target=2*left_sum+1;
            auto it=upper_bound(prefix.begin(),prefix.end(),target);
            ll k=(long long)(it-prefix.begin())-1;
            ans=max(ans,k);
        }else if(left_sum>right_sum){
            ll target=prefix[s]-right_sum;

            auto it=lower_bound(prefix.begin(),prefix.begin()+s+1,target);
            ll k=(long long)(it-prefix.begin());
            ans=max(ans,n-k);
        }
    }

    cout<<ans<<endl;
}