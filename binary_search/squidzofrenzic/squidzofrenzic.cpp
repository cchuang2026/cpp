#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main(){
    int n,m;
    //m is the number of squids

    cin >> n >>m;
    vector<int> b(n);

  
    int low=0;
    int total=0;
    for(int i=0;i<n;i++){
        cin >> b[i];
        low=max(low,b[i]);
        total+=b[i];
    }

    int high=total;
    int ans=high;
    while(low<=high){
        int mid=low+(high-low+1)/2; 
        //mid is the max num of boxes
        //given to one squid


        int squids_needed=1;
        int cur=0;
        bool possible=true;
        for(auto &x:b){
            if(cur+x>mid){
                squids_needed++;
                cur=x;
                if(squids_needed>m){
                    possible=false;
                    break;
                }
            }else {
                cur+=x;
            }
        }

        if(possible){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }

    cout<<ans;

}