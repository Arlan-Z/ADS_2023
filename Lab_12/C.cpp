#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 410;
vector<int> g_road[MAXN];
vector<int> g_air[MAXN];
int road[MAXN][MAXN];

void bfs(vector<int> &d, vector<bool> &used, vector<int> g[]) {
    queue<int> q;
    q.push(0);
    used[0] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            if (!used[to]) {
                used[to] = true;
                q.push(to);
                d[to] = d[v] + 1;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g_road[--a].push_back(--b);
        g_road[b].push_back(a);
        road[a][b] = road[b][a] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (road[i][j] == 0 && i != j) {
                g_air[i].push_back(j);
                g_air[j].push_back(i);
            }
        }
    }

    vector<int> d_road(n + 1), d_air(n + 1);
    vector<bool> used_road(n + 1, false), used_air(n + 1, false);

    bfs(d_road, used_road, g_road);
    bfs(d_air, used_air, g_air);

    if (!used_road[n - 1] || !used_air[n - 1]) {
        cout << -1;
    } else {
        cout << max(d_road[n - 1], d_air[n - 1]);
    }

    return 0;
}


