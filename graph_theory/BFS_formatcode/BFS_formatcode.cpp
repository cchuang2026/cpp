#include<iostream>
#include<queue>

using namespace std;
int r,c;
int grid[10005][10005];
bool visited[10005][10005];
int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};
//in a grid
void bfs(int starti,int startj){
    queue<pair<int,int>> q;
    q.push({starti,startj});
    
    while(!q.empty()){
        int cur_i=q.front().first;
        int cur_j=q.front().second;

        //we iterate through all the neighbors of this element 
        //that might be 4(without diagnols),or 8 (with diagnols)

        for(int idx=0;idx<4;idx++){
            int next_i=cur_i+dx[idx];
            int next_j=cur_i+dy[idx];

            if (next_i < 0 || next_i >= r || next_j < 0 || next_j >= c) continue;

            if(!visited[next_i][next_j]){
                visited[next_i][next_j]=true;
                q.push({next_i,next_j});
            }
        }
    }
}