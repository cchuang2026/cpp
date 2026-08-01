#include<iostream> 
#include<vector>
#include<algorithm>

using namespace std;
vector<vector<pair<int,int>>> adjlist;
vector<long long> height;
vector<bool> visited;

void dfs(int u,long long h){
//u is the node we are into
//h is the relative height from the root node
    visited[u]=true;
    height[u]=h;

    for(auto [v,w]:adjlist[u]){
        if(!visited[v]){
            dfs(v,h+w);
        }
    }
}
int main(){
    int n;
    cin >> n;

    adjlist.assign(n+1,0);
    height.assign(n+1,0);
    visited.assign(n+1,false);

    for(int i=1;i<=n;i++){
        int a,b,h;
        cin >> a >> b >>h;
        adjlist[a].push_back({b,h});
        adjlist[b].push_back({a,-h});
        
    }

    dfs(1,0);
}