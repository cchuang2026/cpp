#include <iostream>
#include<vector>
//usual dijkstra implementation
using namespace std;

const long long INF = 1e18;

vector<long long> dijkstra(int n, int src, const vector<vector<pair<int, long long>>>& g) {
    vector<long long> dist(n + 1, INF);
    dist[src] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;

        for (auto [v, w] : g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, C, Ts, Te;
    cin >> T >> C >> Ts >> Te;

    vector<vector<pair<int, long long>>> g(T + 1);
    for (int i = 0; i < C; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);   // undirected
    }

    auto dist = dijkstra(T, Ts, g);
    cout << dist[Te] << "\n";
}