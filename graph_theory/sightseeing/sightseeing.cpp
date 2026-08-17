#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF=1e9;
int v,e,q;
bool check(vector<vector<pair<int,int>>>& adjlist,int beingchecked,int target){
    vector<int> d(v+5,INF);
    d[1]=0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        int cur_node=pq.top().second;
        int cur_weight=pq.top().first;
        pq.pop();
        if(d[cur_node]<cur_weight) continue;

        for(auto[next_weight,next_node]:adjlist[cur_node]){
            if(next_weight<beingchecked) next_weight=1;
            else next_weight=0;

            if(d[next_node]>d[cur_node]+next_weight){
                d[next_node]=d[cur_node]+next_weight;
                pq.push({d[next_node],next_node});
            }
        }
    }
    
    return d[target]==0;

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> v >>e>>q;
    vector<vector<pair<int,int>>> adjlist(v+5);//one based
    vector<int> allVal(e);

    for(int i=0;i<e;i++){
        int v1,v2,w;
        cin >> v1 >> v2 >> w;
        adjlist[v1].push_back({w,v2});
        adjlist[v2].push_back({w,v1});
        allVal[i]=w;
    }

    sort(allVal.begin(),allVal.end());

   for(int i=0;i<q;i++){

        int target;
        cin >> target;
        int low=0;
        int high=e-1;
        int ans=allVal[high];

        while(low<=high){

            int mid=(low+high)/2;
            
            if(check(adjlist,allVal[mid],target)){
                ans=allVal[mid];
                low=mid+1;
            }else{
                high=mid-1;
            }

        }

        cout<<ans<<endl;

   }
}