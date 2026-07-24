#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
//3(n) 1(s) 1(b)
// 2 v[0]
// 11 v[1]
// 17 v[2]
bool check(vector<int>& v,int w,int n){
    vector<int> next_small(n);
    vector<int> next_large(n);
    for(int i=0;i<n;i++){
        int small_reach=v[i]+w-1;
        int large_reach=v[i]+2*w-1;
        next_small[i]=(int)(upper_bound(v.begin(),v.end(),small_reach)-v.begin());
        next_large[i]=(int)(upper_bound(v.begin(),v.end(),large_reach)-v.begin());
    }
    cout<<0;

}
int main(){
    freopen("watching.in", "r", stdin);
    int n,s,b;
    cin >> n >>s>>b;

    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];

    sort(v.begin(),v.end());
    check(v,4,n);
    
    int low=1;
    int high=v[n-1]-v[0];
    
    while(low<high){
        int mid=(low+high)/2;

        if(check(v,mid,n)){
            
            high=mid;
        }else{
            low=mid+1;
        }

    }
    cout<<low<<endl;

    
}