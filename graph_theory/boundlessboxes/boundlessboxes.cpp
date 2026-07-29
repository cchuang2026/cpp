#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int grid[1005][1005];
    bool visited[1005][1005];
    int dist[1005][1005];
    vector<int>  starti;
    vector<int> startj;
    queue<pair<int,int>> q; //q stores the coordinates of the "nextis and nextjs" that are visiteed
int main(){
    int n,m;
    cin >> n >> m;
    

    int s;
    cin >> s;
    //here r is i, and c is j
    for(int idx=0;idx<s;idx++){
        int r,c;
        cin >> r>>c;
        starti.push_back(r);
        startj.push_back(c);

        dist[r][c]=0;
        visited[r][c]=true;
        q.push({r,c});
    }

    int dx[8]={0,0,1,1,1,-1,-1,-1};
    int dy[8]={1,-1,0,1,-1,-1,0,1};
    int ans=0;
    // ans is going to be max distance + 1
    while(!q.empty()){
        int cur_i=q.front().first;
        int cur_j=q.front().second;
        q.pop();

        for(int idx=0;idx<8;idx++){
            int next_i=cur_i+dx[idx];
            int next_j=cur_j+dy[idx];

            if(next_i<=n && next_i>=1 && next_j<=m && next_j>=1 && !visited[next_i][next_j]){
                visited[next_i][next_j]=true;
                dist[next_i][next_j]=dist[cur_i][cur_j]+1;

                q.push({next_i,next_j});
                if(dist[next_i][next_j]>ans) ans=dist[next_i][next_j];
            }
        }

    }

    cout<<ans+1;

}