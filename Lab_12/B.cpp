#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int INF = 1e9;
vector<pair<int, int>> g[200001];
vector<int> d(200001, INF);

int dijkstra(int start, int end) {
    d.assign(200001, INF);
    d[start] = 0;
    
    set<pair<int, int>> q;
    q.insert({0, start});

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (const auto& edge : g[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }
    }

    return d[end];
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    int q, w, e, r;
    cin >> q >> w >> e >> r;

    int path1 = dijkstra(q, w) + dijkstra(w, e) + dijkstra(e, r);
    int path2 = dijkstra(q, e) + dijkstra(e, w) + dijkstra(w, r);

    int result = min(path1, path2);

    if (result <= INF) {
        cout << result;
    } else {
        cout << -1;
    }

    return 0;
}



