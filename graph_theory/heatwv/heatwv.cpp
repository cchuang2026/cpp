#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int t,c,ts,te;
    cin >> t >> c >>ts>>te;

    vector<vector<pair<int,int>>> adjlist(t+1);
    //weight,node
    //one based 
    for(int i=1;i<=c;i++){
        int r1,r2,w;
        cin >> r1 >> r2 >> w;
        adjlist[r1].push_back({w,r2});
        adjlist[r2].push_back({w,r1});
    }

    int dist[t+1];
    const int INF=1e9;
    for(int i=1;i<=t;i++) dist[i]=INF;
    dist[ts]=0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0,ts});

    while(!pq.empty()){
        int cur_node=pq.top().second;
        int cur_dist=pq.top().first;
        pq.pop();

        if(cur_dist>dist[cur_node]) continue;

        for(auto[w,neighbour]:adjlist[cur_node]){
            if(dist[cur_node]+w<dist[neighbour]){
                dist[neighbour]=dist[cur_node]+w;
                pq.push({dist[neighbour],neighbour});
            }
        }
    }

    cout<<dist[te]<<endl;

}