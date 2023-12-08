#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> parent(1001);

int findSet(int v) {
    return (v == parent[v]) ? v : (parent[v] = findSet(parent[v]));
}

void uniteSets(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (rand() & 1) {
        swap(a, b);
    }
    if (a != b) {
        parent[a] = b;
    }
}

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<pair<int, pair<int, int>>> roads;

    while (m--) {
        string roadType;
        int a, b, c;
        cin >> roadType >> a >> b >> c;

        if (roadType == "big") {
            roads.push_back(make_pair(c * x, make_pair(a, b)));
        } else if (roadType == "small") {
            roads.push_back(make_pair(c * y, make_pair(a, b)));
        } else if (roadType == "both") {
            roads.push_back(make_pair(c * x, make_pair(a, b)));
            roads.push_back(make_pair(c * y, make_pair(a, b)));
        }
    }

    int roadCount = roads.size(), totalCost = 0;
    vector<pair<int, int>> selectedRoads;

    sort(roads.begin(), roads.end());

    parent.resize(n);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < roadCount; ++i) {
        int cityA = roads[i].second.first, cityB = roads[i].second.second, cost = roads[i].first;

        if (findSet(cityA) != findSet(cityB)) {
            totalCost += cost;
            selectedRoads.push_back(roads[i].second);
            uniteSets(cityA, cityB);
        }
    }

    cout << totalCost;

    return 0;
}

