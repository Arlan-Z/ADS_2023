#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 200005;

int parent[MAXN], r_rank[MAXN];
vector<int> adj[MAXN], result;

void initializeDSU() {
    for (int i = 0; i < MAXN; i++) {
        parent[i] = i;
        r_rank[i] = 1;
    }
}

int findRoot(int v) {
    return (parent[v] == v) ? v : (parent[v] = findRoot(parent[v]));
}

bool uniteSets(int a, int b) {
    int rootA = findRoot(a);
    int rootB = findRoot(b);

    if (rootA == rootB) {
        return false;
    } else {
        if (r_rank[rootA] < r_rank[rootB]) {
            parent[rootA] = rootB;
        } else if (r_rank[rootB] < r_rank[rootA]) {
            parent[rootB] = rootA;
        } else {
            parent[rootA] = rootB;
            r_rank[rootB]++;
        }
        return true;
    }
}

int main() {
    int n, m, cnt = 0;
    initializeDSU();

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = n; i >= 1; i--) {
        cnt++;

        for (int j : adj[i]) {
            if (i < j && findRoot(i) != findRoot(j)) {
                cnt--;
                uniteSets(i, j);
            }
        }

        result.push_back(cnt);
    }

    reverse(result.begin(), result.end());

    for (int i = 1; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    cout << 0 << endl;

    return 0;
}


