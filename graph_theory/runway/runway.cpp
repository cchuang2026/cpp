#include <iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF = 1e9;
int n, e, k;
vector<vector<pair<int,int>>> adjlist;

bool check(int x) {
    vector<int> cost(n+1,INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    cost[1]=0;
    pq.push({0,1}); //weight , node

    while(!pq.empty()){
        int cw=pq.top().first;

        int cur_node=pq.top().second;
        pq.pop();

        if(cw>cost[cur_node]) continue;

        for(auto[nw,next_node]:adjlist[cur_node]){
            int next_weight=(nw>x)?1:0;

            if(cost[next_node]>cost[cur_node]+next_weight){
                cost[next_node]=cost[cur_node]+next_weight;

                pq.push({cost[next_node],next_node});
            }
        }
    }
    return cost[n] <= k - 1;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // freopen("sample.in","r",stdin);
    cin >> n >> e >> k;
    adjlist.resize(n+5);
    
    vector<int> allD;
    
    for (int i = 0; i < e; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        adjlist[a].push_back({d, b});   // {weight, node}
        adjlist[b].push_back({d,a});
        allD.push_back(d);
    }
    
   //bfs to see if can output -1

   vector<int> dist(n+1,INF);//dist from 1
    vector<bool> visited(n+1,false);
    visited[1]=true;
    dist[1]=0;
    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int cur_node=q.front();
        q.pop();

        for(auto [w,next_node]:adjlist[cur_node]){
            //w is just useless
            if(visited[next_node]) continue;

            visited[next_node]=true;
            dist[next_node]=dist[cur_node]+1;
            q.push(next_node);
        }

    }

    if(dist[n]<k){
        cout<<-1<<endl;
        return 0;
    }

    sort(allD.begin(),allD.end());
    int low=0;
    int high=(int)allD.size()-1;
    int ans=high;
    
    while(low<=high){
        int mid=(low+high)/2;
        int x=allD[mid];

    if (check(x)) {
        ans = x;
        high = mid - 1;   // try smaller
    } else {
        low = mid + 1;
    }
    }

    cout<<ans<<endl;
    return 0;
}