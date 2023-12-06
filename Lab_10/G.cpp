#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> adjacencyList[501], cyclePath;
int visited[501];
stack<int> dfsStack;
bool isCyclic = false;

bool dfs(int current, int avoidA, int avoidB) {
    visited[current] = 1;
    for (int neighbor : adjacencyList[current]) {
        if (current == avoidA && avoidB == neighbor) continue;
        if (!visited[neighbor]) {
            if (dfs(neighbor, avoidA, avoidB)) return true;
        } else if (visited[neighbor] == 1) {
            return true;
        }
    }
    visited[current] = 2;
    return false;
}

bool findCycle(int current) {
    visited[current] = 1;
    dfsStack.push(current);

    for (int neighbor : adjacencyList[current]) {
        if (!visited[neighbor]) {
            if (findCycle(neighbor)) return true;
        } else if (visited[neighbor] == 1) {
            while (dfsStack.top() != neighbor) {
                cyclePath.push_back(dfsStack.top());
                dfsStack.pop();
            }
            cyclePath.push_back(neighbor);
            cyclePath.push_back(current);
            reverse(cyclePath.begin(), cyclePath.end());
            return true;
        }
    }

    visited[current] = 2;
    if (!dfsStack.empty()) {
        dfsStack.pop();
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjacencyList[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            isCyclic = findCycle(i);
            if (isCyclic) {
                break;
            }
        }
    }

    if (!isCyclic) {
        cout << "YES";
        return 0;
    }

    for (int i = 0; i < cyclePath.size() - 1; i++) {
        int u = cyclePath[i], v = cyclePath[i + 1];

        for (int j = 1; j <= n; j++) {
            visited[j] = 0;
        }

        isCyclic = false;
        for (int j = 1; j <= n; j++) {
            if (!visited[j]) {
                isCyclic |= dfs(j, u, v);
            }
        }

        if (!isCyclic) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";

    return 0;
}




