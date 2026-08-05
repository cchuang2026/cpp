#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    const int INF=1e18;
    int n,kx,ky,px,py,t;
    cin >> n >> kx>>ky >> px>> py >>t;

    vector<vector<bool>> grid(n+1,vector<bool> (n+1,true));
    vector<vector<int>> dist(n+1,vector<int> (n+1,INF));
    for(int i=1;i<=t;i++){
        int fx,fy;
        cin >> fx >> fy;
        grid[fx][fy]=false;

    }
     vector<vector<bool>> visited(n+1,vector<bool> (n+1,false));
     
    queue<pair<int,int>> q;
    q.push({kx,ky});
    visited[kx][ky]=true;
    dist[kx][ky]=0;

    int dx[8]={1,1,2,2,-1,-1,-2,-2};
    int dy[8]={2,-2,-1,1,2,-2,1,-1};

    while(!q.empty()){
        int cur_x=q.front().first;
        int cur_y=q.front().second;
        q.pop();

        for(int idx=0;idx<8;idx++){
            int next_x=cur_x+dx[idx];
            int next_y=cur_y+dy[idx];

            if(next_x>=1 && next_x<=n){
                if(next_y>=1 && next_y<=n){
                    if(grid[next_x][next_y] && !visited[next_x][next_y]){
                        visited[next_x][next_y]=true;
                        dist[next_x][next_y]=dist[cur_x][cur_y]+1;
                        q.push({next_x,next_y});
                    }
                }

            }
        }
    }

     if(dist[px][py]==INF) cout<<-1<<endl;
     else cout<<dist[px][py]<<endl;
     return 0;

}