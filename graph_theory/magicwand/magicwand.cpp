#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int h,w,x,y,t;
    cin >> h >> w >> x >> y >> t;
    vector<vector<int>> grid(h+1,vector<int> (w+1));
    //1 based
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> grid[i][j];
        }
    }
    vector<vector<bool>> visited(h+1, vector<bool>(w+1, false));

    vector<vector<int>> ans(h+1,vector<int>(w+1,0));
    //also 1 based 
    queue<pair<int,int>> q;
    //q stores he cooridnates
    q.push({x,y});
    visited[x][y]=true;
    ans[x][y]=1;
    
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};

    while(!q.empty()){
        int cur_x=q.front().first;
        int cur_y=q.front().second;
        q.pop();

        for(int idx=0;idx<4;idx++){
            int next_x=cur_x+dx[idx];
            int next_y=cur_y+dy[idx];

            if(next_x>=1 && next_x<=h){
                if(next_y>=1 && next_y<=w && !visited[next_x][next_y]){
                    if(abs(grid[next_x][next_y] - grid[x][y]) <= t){
                        ans[next_x][next_y]=1;
                        visited[next_x][next_y]=true;
                        q.push({next_x,next_y});
                    }
                }
            }
        }

    
    }

     for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                cout<<ans[i][j];
            }
            cout<<endl;
        }
}