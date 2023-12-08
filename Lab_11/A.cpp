#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, l, r, c, parent[200002], leftmost[200002], rightmost[200002];

int find(int i) {
    if (i == parent[i]) {
        return i;
    }
    return parent[i] = find(parent[i]);
}

void unionSets(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) {
        return;
    }

    parent[a] = b;
    leftmost[b] = min(leftmost[a], leftmost[b]);
    rightmost[b] = max(rightmost[a], rightmost[b]);
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        parent[i] = i;
        leftmost[i] = i;
        rightmost[i] = i;
    }

    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < m; i++) {
        cin >> l >> r >> c;
        l--;
        r--;
        edges.push_back({c, {l, r}});
    }

    sort(edges.begin(), edges.end());

    long long ans = 0;
    int components = 0, representative = -1;

    for (int i = 0; i < m; i++) {
        if (components > n - 1) {
            break;
        }

        int left = edges[i].second.first;
        int right = edges[i].second.second;
        int cost = edges[i].first;

        representative = left;

        for (int j = left; j <= right; j++) {
            if (j != find(j)) {
                representative = find(j);
                break;
            }
        }

        if (leftmost[representative] <= left && right <= rightmost[representative]) {
            continue;
        } else if (leftmost[representative] <= right && right <= rightmost[representative]) {
            right = leftmost[representative];
        } else if (leftmost[representative] <= left && left <= rightmost[representative]) {
            left = rightmost[representative];
        }

        for (int j = left; j <= right; j++) {
            if (find(representative) != find(j)) {
                unionSets(representative, j);
                components++;
                ans += cost;
            }
        }
    }

    cout << ans;

    return 0;
}
