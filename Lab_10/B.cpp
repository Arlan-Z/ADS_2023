#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n][n], minStep[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int from, to;
    cin >> from >> to;
    from--; to--;

    queue<int> q;
    for (int i = 0; i < n; i++) {
        minStep[i] = -1;
    }

    minStep[from] = 0;
    q.push(from);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < n; i++) {
            if (a[cur][i] == 1 && minStep[i] < 0) {
                q.push(i);
                minStep[i] = minStep[cur] + 1;
            }
        }
    }

    cout << minStep[to];

    return 0;
}

