#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 1;

vector<int> adjacencyList[MAXN], topologicalOrder;
int visitStatus[MAXN];

void dfs(int vertex) {
    if (visitStatus[vertex] == 1) {
        cout << "Impossible\n";
        exit(0);
    }

    if (visitStatus[vertex] == 2) {
        return;
    }

    visitStatus[vertex] = 1;

    for (int i = 0; i < adjacencyList[vertex].size(); i++) {
        int neighbor = adjacencyList[vertex][i];
        dfs(neighbor);
    }

    visitStatus[vertex] = 2;
    topologicalOrder.push_back(vertex);
}

int main() {
    int n, m;
    cin >> n >> m;

    while (m--) {
        int i, j;
        cin >> i >> j;
        adjacencyList[i].push_back(j);
    }

    for (int i = 1; i <= n; i++) {
        if (visitStatus[i] == 0) {
            dfs(i);
        }
    }

    cout << "Possible\n";

    reverse(topologicalOrder.begin(), topologicalOrder.end());

    for (int i = 0; i < topologicalOrder.size(); i++) {
        cout << topologicalOrder[i] << " ";
    }

    return 0;
}




