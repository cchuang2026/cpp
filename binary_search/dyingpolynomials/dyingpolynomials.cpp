#include<iostream>

using namespace std;
typedef long long ll;
typedef __int128 superll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll q;
    cin >> q;

    for(ll i=0;i<q;i++){
        freopen("sample.in", "r", stdin);
        ll a,b,c,d;
        cin >> a>>b>>c>>d;

        ll low=0;
        ll high=100000;
        ll ans=high;//for worse case

        while(low<=high){
            ll mid=low+(high-low)/2;

            superll val=(superll)a*mid*mid*mid+
                        (superll)b*mid*mid+
                        (superll)c*mid;

            if(val>=d){
                //viable then try smaller cases
                high=mid-1;
                ans=mid;
            }else{
                low=mid+1;
            }
        }

        cout<<ans<<endl;

    }

  
    return 0;
}