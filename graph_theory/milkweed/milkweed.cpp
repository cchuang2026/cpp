#include<iostream>
#include<queue>
using namespace std;

int x,y,mx,my;
char grid[105][105];
bool visited[105][105];
int dist[105][105];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1,  0,  1,-1, 1,-1, 0, 1};

int main(){

    cin >> x >> y >> mx >> my;
    my=y-my+1;

    for(int j=1;j<=y;j++){
        for(int i=1;i<=x;i++){
            char s;
            cin >> s;
            grid[i][j]=s;
        }
    }

    queue<pair<int,int>> q;
    q.push({mx,my});
    visited[mx][my]=true;
    dist[mx][my]=0;

    int ans=0;
    while(!q.empty()){
        int cur_i=q.front().first;
        int cur_j=q.front().second;
       
        q.pop();
        ans=max(ans,dist[cur_i][cur_j]);

        for(int idx=0;idx<8;idx++){

                int next_i=cur_i+dx[idx];
                int next_j=cur_j+dy[idx];
                

                if(!visited[next_i][next_j] && next_i>=1 && next_i<=x && next_j<=y && next_j>=1 && grid[next_i][next_j]=='.'){
                   
                    dist[next_i][next_j]=dist[cur_i][cur_j]+1;
                    
                    q.push({next_i,next_j});
                     visited[next_i][next_j]=true;

                }

            
        }

    }

    cout<<ans<<endl;
    return 0;
   

}