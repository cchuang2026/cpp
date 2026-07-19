#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

bool canbuild(vector<ll>& a,vector<ll>& b,ll mid,ll n){
    //mid is the height of roof 
    vector<ll> days_to_exceed(n);

    for(int i=0;i<n;i++){
        days_to_exceed[i]=(mid-a[i])/b[i];
        if(a[i]>mid) return false;
    }

    sort(days_to_exceed.begin(),days_to_exceed.end());

    for(int i=0;i<n;i++){
        if(days_to_exceed[i]<i)return false;
    }
    
    return true;

}


int main(){
    ll n;
    cin >> n;
    vector<ll> a(n),b(n);

    ll low=INT_MAX;
    bool task2=true;
    ll greatest_sum=LLONG_MIN;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cin >> b[i];

        if(i>0){
            if(a[i]!=a[i-1]) task2=false;
        }

        
        low=min(low,a[i]);
        greatest_sum=max(greatest_sum,a[i]+n*b[i]);
    }

    // height on that day=a[i]+day*b[i];


    if(task2){
       
        sort(b.begin(),b.end());
        vector<ll> v(n);
        for(int i=0;i<n;i++){
           
            v[i]=a[i]+(n-i-1)*b[i];
            
        }

        sort(v.begin(),v.end());
        cout<<v[n-1];
        return 0;
    }

    ll high=greatest_sum;
    ll ans=high;

//we are searching for the roof height
    while(low<=high){
        ll mid=low+(high-low)/2;

        //check if any tree exceeds
        if(canbuild(a,b,mid,n)){
            // if this wokrs try smaller mid
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }

    }

    cout<<ans<<endl;
    return 0;
}