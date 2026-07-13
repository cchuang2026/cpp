#include <iostream>
#include<vector>
#include<map>
using namespace std;

int main() {
// freopen("sample.in","r",stdin);
	int n,k;
    cin >> n >> k;
    vector<int> p(n);

    long long initial_friends=0;
    unordered_map<int,long long> cnt;

    for(int i=0;i<n;i++) {
        cin >> p[i];
        cnt[p[i]]++;
    }

    for (auto& entry : cnt) {
        long long c = entry.second;
        initial_friends += c*(c-1)/2;
    }

    string d;
    cin >> d;
    
    vector<int> R_e;
    vector<int> L_e;
    vector<int> R_o;
    vector<int> L_o;
    //put the monkeys initial pos into the groups
    for(int i=0;i<n;i++){
        if(p[i]%2==0){
            if(d[i]=='R'){
                R_e.push_back(p[i]);
            }else{
                L_e.push_back(p[i]);
            }
        }else{
            if(d[i]=='R'){
                R_o.push_back(p[i]);
            }else{
                L_o.push_back(p[i]);
            }
        }
    }

long long total=0;
    //now lets do for the even group
    sort(L_e.begin(),L_e.end());

    int temp=R_e.size();
    for(int i=0;i<temp;i++){
        int cur_r=R_e[i];
        //the bounds we want for l is [cur_r+2,cur_r+2k]
        long long target_upper = cur_r + 2LL*k;
if (target_upper > INT_MAX) target_upper = INT_MAX;

auto lb=lower_bound(L_e.begin(),L_e.end(),cur_r+2);
auto ub=upper_bound(L_e.begin(),L_e.end(),(int)target_upper);
        long long count= ub-lb;
        total+=count;
    }

    sort(L_o.begin(),L_o.end());

    int temp2=R_o.size();
    for(int i=0;i<temp2;i++){
        int cur_r=R_o[i];
        //the bounds we want for l is [cur_r+2,cur_r+2k]
       long long target_upper = cur_r + 2LL*k;
if (target_upper > INT_MAX) target_upper = INT_MAX;

auto lb=lower_bound(L_o.begin(),L_o.end(),cur_r+2);
auto ub=upper_bound(L_o.begin(),L_o.end(),(int)target_upper);
        long long count= ub-lb;
        total+=count;
    }

    total+=initial_friends;
    cout<< total<<endl;
    return 0;
    
}
