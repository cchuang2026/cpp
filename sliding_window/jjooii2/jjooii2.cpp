#include<iostream>
#include<vector>
using namespace std;

int main(){
    freopen("sample.in","r",stdin);
    int n,k;
    string s;
    cin >> n >> k;
    cin >> s;

    vector<int> pos_j,pos_o,pos_i;
    for(int i=0;i<n;i++){
        if(s[i]=='J'){
           pos_j.push_back(i);
        }else if(s[i]=='O'){
            pos_o.push_back(i);
        }else{
            pos_i.push_back(i);
        }
    }

    int ans=INT_MAX;
    
    if(pos_j.size()<k || pos_o.size()<k || pos_i.size()<k){
        cout<<-1;
        return 0;
    }

    for(int idx=0;idx<(int)pos_i.size()-k+1;idx++){
        int last_i=pos_i[idx+k-1];
        int first_i=pos_i[idx];

        auto it=upper_bound(pos_o.begin(),pos_o.end(),first_i);
        int cnt_o=it-pos_o.begin();
        if(cnt_o<k) continue;

        int first_o=pos_o[cnt_o-k];

        auto it2=upper_bound(pos_j.begin(),pos_j.end(),first_o);
        int cnt_j=it2-pos_j.begin();
        if(cnt_j<k)continue;

        int first_j=pos_j[cnt_j-k];

        int cur_cost=last_i-first_j+1-3*k;

        ans=min(cur_cost,ans);
    }

   if(ans==INT_MAX){
       cout<<-1<<endl;
   }else{
       cout << ans <<endl;
   }
    return 0;
}