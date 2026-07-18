#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
typedef long long ll;
int main(){
    // freopen("sample.in","r",stdin);
    int n,k;
    cin >> n >>k;
    bool allpos=true;
    vector<int> v;


    long long sum=0;
    for(int i=0;i<n;i++){
        int temp;
        cin>> temp;
        sum+=temp;
        if(temp<0) allpos=false;
        v[i]=temp;
        
    }

    if(allpos) {
        cout<<sum;
        return 0;
    }

    if(k==1){
        //use kadanes algorithm
        ll global_max=LLONG_MIN;
        ll cur_max=0;

        int r=0;
        while(r<n){

            cur_max=max(cur_max+(ll)v[r],(ll)v[r]);
            global_max=max(cur_max,global_max);
            r++;
        }

        cout<<global_max;
        return 0;
    }

    
}