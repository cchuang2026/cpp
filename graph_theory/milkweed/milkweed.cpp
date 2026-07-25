#include <iostream>
#include<queue>

using namespace std;

int main() {
    int X, Y, Mx, My;
    cin >> X >> Y >> Mx >> My;
    vector<string> grid(Y);
    for (int i = 0; i < Y; i++) {
        cin >> grid[i];
    }
    // grid[0] is top row (row Y), grid[Y-1] is bottom row (row 1)
    // convert start to 0-based array indices
    int sr = Y - My;
    int sc = Mx - 1;

    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    vector<vector<int>> dist(Y, vector<int>(X, -1));
    queue<pair<int, int>> q;
    if (grid[sr][sc] == '.') {
        dist[sr][sc] = 0;
        q.push({sr, sc});
    }

    int maxd = 0;
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        maxd = max(maxd, dist[r][c]);
        for (int k = 0; k < 8; k++) {
            int nr = r + dx[k];
            int nc = c + dy[k];
            if (nr >= 0 && nr < Y && nc >= 0 && nc < X && grid[nr][nc] == '.' && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
    cout << maxd << endl;
    return 0;
}