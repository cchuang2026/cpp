#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long total_cnt=0;
long long cur_cnt=0;
int a,b,c,d,e;

void dfs(int src,vector<vector<pair<int,int>>>& adjlist, vector<bool>& visited){
       if(visited[src]) cur_cnt=0;

        for(auto [next_weight,next_node]:adjlist[src]){
            cur_cnt+=next_weight;
            if(visited[next_node]) continue;
            else visited[next_node]=true;

            if(next_node==a || next_node==b ||next_node==c ||next_node==d ||next_node==e ){
                //if the next_node is the target
                total_cnt+=cur_cnt;
                cur_cnt=0;
                
            }else{

            }

            dfs(next_node,adjlist,visited);
        }

}



int main(){
    int v;
    cin >> v;
    vector<vector<pair<int,int>>> adjlist(v);
    //weight, node
    for(int i=0;i<v-1;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adjlist[v].push_back({w,u});
        adjlist[u].push_back({w,v});
    }
    int q;cin>>q;
     cin >> a >> b >> c >>d >>e;

    int src=a;
    vector<bool> visited(v,false);
    vector<int> cnt(v,0);

    cnt[src]=0;

    dfs(src,adjlist,visited);
    cout<<total_cnt<<endl;
    return 0;
}