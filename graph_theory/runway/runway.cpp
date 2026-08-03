#include <iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF = 1e9;

bool can(int x, vector<vector<pair<int,int>>>& adjlist, int n, int k) {
    vector<int> cost(n+1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, e, k;
    cin >> n >> e >> k;
    
    vector<vector<pair<int,int>>> adjlist(n + 1);
    vector<int> allD;
    
    for (int i = 0; i < e; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        adjlist[a].emplace_back(d, b);   // {weight, node}
        adjlist[b].emplace_back(d, a);
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
        }

    }

    if(dist[n]<k){
        cout<<-1<<endl;
        return 0;
    }

    int low=0;
    int high=(int)allD.size()-1;
    int ans=high;
    
    while(low<=high){
        int mid=(low+high)/2;
        int x=allD[mid];


    }
}