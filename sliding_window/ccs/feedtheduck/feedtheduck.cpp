#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;

int main(){

    ll n,k;
    cin >> n>>k;
    vector<ll> a(n);

    for(int i=0;i<n;i++) cin >> a[i];
    freopen("sample.in","r",stdin);
    vector<ll> prefix(n);
    prefix[0]=a[0];
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+a[i];
    }

    int left=0;
    ll cur_sum=0;
    ll global_min=LLONG_MAX;
    for(int right=0;right<n;right++){

       if(left>0) cur_sum=prefix[right]-prefix[left-1];
       else if(left==0) cur_sum=prefix[right];

        while(cur_sum-prefix[left]>=k && left<n){
            cur_sum-=prefix[left];
            left++;
        }
        //now left is still in the valid range
        global_min=min(global_min,cur_sum);

    }

    cout<<global_min<<endl;
    return 0;
}