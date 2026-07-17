#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;
typedef long long ll;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("sample.in", "r", stdin);
    ll n,m;
    cin >> n>>m; //n is number of children
    vector<ll> colours(m);
    ll min=1;
    ll max=0;

    for(int i=0;i<m;i++){
        cin>>colours[i];
       if(max<=colours[i]){
        max=colours[i];
       }
    }

    ll low=min;
    ll high=max;
    ll ans=high; //for worse case
    while(low<=high){

        ll mid=low+(high-low)/2;

        ll children_needed=0;
        for(auto &colour:colours){
            if(colour%mid==0) children_needed+=colour/mid;
            else children_needed+=colour/mid +1;
        }

        if(children_needed<=n){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }

    
    }
    cout<<ans<<endl;
    return 0;
}