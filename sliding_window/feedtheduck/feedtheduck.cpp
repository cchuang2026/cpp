#include<iostream>
#include<algorithm>
#include<algorithm>
#include <climits>
using namespace std;
typedef long long ll;

int main(){
    
    // freopen("sample.in","r",stdin);
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<ll> prefix(n+1,0);
    for(int i=1;i<=n;i++){
        prefix[i]=prefix[i-1]+a[i-1];
    }

    //note that the pointers here are the indices of the prefix array 
    //prefix[right]-prefix[left]=original[left+1] to original[right]
    int left=0;
    ll global_min=LLONG_MAX;
    for(int right=1;right<=n;right++){

        while(prefix[right]-prefix[left]>=k && left<right){
            left++;
        }

        if(left>0){
            ll cur_sum=prefix[right]-prefix[left-1];
            if(cur_sum>=k) global_min=min(global_min,cur_sum);
        }

   
    }
    

    cout<<global_min<<endl;
    return 0;
}