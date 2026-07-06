#include "molecules.h"
#include <iostream>
using namespace std;


vector<int> find_subset(int l, int u, vector<int> w) {
    int min_sum = 0;
    int max_sum = 0;
    int n=w.size();
    vector<pair<int,int>> v;
    for (int i = 0; i < w.size(); i++) {
        v.push_back(make_pair(w[i], i));
    }
    //4 15 17
    //6 7 8 8

    sort(v.begin(),v.end());
    int right=0;
    long long cur_sum=0;
    for(int left=0;left<n;left++){
        if(left>0){
            cur_sum-=v[left-1].first;
        }
        
        while(right<n && cur_sum+v[right].first<=u){
            cur_sum+=v[right].first;
            right++;
        }

        if(cur_sum>=l){
            vector<int> ans;

            for(int i=0;i<right-left+1;i++){
                ans.push_back(v[i].second);
            }
            return ans;
        }
    }
return vector<int>();
}