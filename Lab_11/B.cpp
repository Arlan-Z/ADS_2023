#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> parent(500);

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
    int n;
    cin >> n;
    int elements[n];
    vector<pair<int, pair<int, int>>> graph;

    for (int i = 0; i < n; i++) {
        cin >> elements[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            graph.push_back(make_pair(elements[i] + elements[j], make_pair(i, j)));
        }
    }

    int edgesCount = graph.size(), totalCost = 0;
    vector<pair<int, int>> resultEdges;

    sort(graph.begin(), graph.end());

    parent.resize(n);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < edgesCount; ++i) {
        int vertexA = graph[i].second.first, vertexB = graph[i].second.second, cost = graph[i].first;

        if (findSet(vertexA) != findSet(vertexB)) {
            totalCost += cost;
            resultEdges.push_back(graph[i].second);
            uniteSets(vertexA, vertexB);
        }
    }

    cout << totalCost;

    return 0;
}
