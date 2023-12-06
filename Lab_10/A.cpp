#include <iostream>
#include <queue>

using namespace std;

struct Index {
    int i, j;
    Index(int i, int j) : i(i), j(j) {}
};

queue<Index> q;
int matrix[1000][1000];

void step(int r, int c, int n, int m) {
    if (r >= 0 && r < n && c >= 0 && c < m && matrix[r][c] == 1) {
        matrix[r][c] = 2;
        q.push(Index(r, c));
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int time = -1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 2) {
                q.push(Index(i, j));
            }
        }
    }

    while (!q.empty()) {
        time++;
        int sz = q.size();

        for (int i = 0; i < sz; i++) {
            Index cur = q.front();
            q.pop();
            step(cur.i - 1, cur.j, n, m);
            step(cur.i + 1, cur.j, n, m);
            step(cur.i, cur.j - 1, n, m);
            step(cur.i, cur.j + 1, n, m);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 1) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    if (time == -1) {
        cout << 0;
    } else {
        cout << time;
    }

    return 0;
}
