#include <iostream>
#include<vector>
#include<queue>
using namespace std;
const int INF=1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	int n,e,q;
    cin >> n >>e>>q;
    vector<vector<pair<int,int>>> adjlist(n+5);
   
    //dist[i][j]is the weight from i to j
    //0 based
    //weight,node
    for(int i=0;i<e;i++){
        int x,y,t;
        cin >> x >> y >>t;
        adjlist[x].push_back({t,y});
        adjlist[y].push_back({t,x});
        
    }
    
    vector<vector<int>> dist(n+5,vector<int> (n+5,INF));

    for(int start=0;start<n;start++){
        vector<int> d(n+5,INF);
        d[start]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  \
        pq.push({0,start});
        
        while(!pq.empty()){
            int cur_node=pq.top().second;
            int cur_weight=pq.top().first;
            pq.pop();

            if(cur_weight>d[cur_node]) continue;

            for(auto[w,next_node]:adjlist[cur_node]){
                
                if(d[next_node]>d[cur_node]+w){
                    d[next_node]=d[cur_node]+w;

                    pq.push({d[next_node],next_node});
                }
            }

        }

        dist[start]=d;
    }

    for(int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;
        if(dist[a][b]==INF) cout<<-1<<endl;
        else cout<<dist[a][b]<<endl;
    }
    return 0;

}
