#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;
typedef long long ll;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("sample.in", "r", stdin);
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
    while(low<=high){

        ll mid=(low+high+1)/2;

        ll children_needed=0;
        for(auto &colour:colours){
            if(colour%mid==0){
                children_needed+=colour/mid;
            }else{
                children_needed+=colour/mid+1;
            }

            if(children_needed==n){
                cout<<mid<<endl;
                return 0;
            }else if(children_needed>n){
                // it means that the mid is too high so set the high to mid
                high=mid;
            }else{
                //mid id too low
                low=mid;
            }
        }
    }
    //this is the brute force approach and it works but TLE
    // for(ll cur=min;cur<=max;cur++){
        
    //     ll children_needed=0;
    //     for(auto &colour:colours){
    //         if(colour%cur==0){
    //             children_needed+=colour/cur;
    //         }else{
    //             children_needed+=colour/cur+1;
    //         }
    //     }

    //     if(children_needed==n){
    //         cout<<cur<<endl;
    //         return 0;
    //     }else{
    //         continue;
    //     }
    // }
}