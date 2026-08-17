#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int V,e;
    cin >> V >>e;
    vector<vector<pair<int,int>>> adjlist(e+5);
    //weight,node (for sorting later)
    // do one based 

    for(int i=0;i<e;i++){
        int x,y,w;
        cin >> x >> y>>w;
        adjlist[x].push_back({w,y});
        adjlist[y].push_back({w,x});
    }

    const int INF=1e9;
    vector<int> dist(e+1,INF);
    //one based

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0,1});
    dist[1]=0;

    while(!pq.empty()){
        int cur_node=pq.top().second;
        int cur_dist=pq.top().first;
        pq.pop();

        if(cur_dist>dist[cur_node]) continue;

        for(auto[w,v]:adjlist[cur_node]){
            // v is the next node
            //weight is the dist from cur_node to next node
            
            if(dist[cur_node]+w<dist[v]){
                dist[v]=cur_dist+w;
                pq.push({dist[v],v});
            }
        }

    }

    if(dist[V]== INF) cout << -1 <<endl;
    else cout<<dist[V]<<endl;
}