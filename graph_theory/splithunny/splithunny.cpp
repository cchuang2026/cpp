#include <iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<queue>
using namespace std;
//flood filling
int r, c;
string grids[105];
bool visited[105][105];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(int starti, int startj) {
    queue<pair<int, int>> q;
    q.push({starti, startj});
    visited[starti][startj] = true;

    while (!q.empty()) {
        int curi = q.front().first;
        int curj = q.front().second;
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int nexti = curi + dir[k][0];
            int nextj = curj + dir[k][1];

            if (nexti < 0 || nexti >= r || nextj < 0 || nextj >= c) continue;
            if (grids[nexti][nextj] != 'H') continue;
            if (!visited[nexti][nextj]) {
                visited[nexti][nextj] = true;
                q.push({nexti, nextj});
            }
        }
    }
}

void dfs(int starti, int startj){
    visited[starti][startj] = true;

    for (int k = 0; k < 4; ++k) {
        int nexti = starti + dir[k][0];
        int nextj = startj + dir[k][1];

        if (nexti < 0 || nexti >= r || nextj < 0 || nextj >= c) continue;
        if (grids[nexti][nextj] != 'H' || visited[nexti][nextj]) continue;
        dfs(nexti,nextj);
    }
}

int main() {
    freopen("sample.in","r",stdin);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> grids[i];
    }

    int pools = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grids[i][j] == 'H' && !visited[i][j]) {
                pools++;
                dfs(i, j);
            }
        }
    }

    cout << "Oh, bother. There are " << pools << " pools of hunny.\n";
    return 0;
}


