#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

unordered_set<int> visited;
queue<pair<int, int>> q;
vector<int> ans;

int bfs(int val, int dist, int target) {
    if (val == target) {
        return dist;
    }

    visited.insert(val);
    ans.push_back(val);

    int temp = -1;

    if (val % 2 == 1 && visited.find(val / 2 + 1) == visited.end() && target < val) {
        temp = (val + 1) / 2;
        ans.push_back(val + 1);
    } else if (val % 2 == 0 && visited.find(val / 2) == visited.end() && target < val) {
        temp = val / 2;
    }

    if (visited.find(val + 1) == visited.end() && target > val) {
        temp = val + 1;
    }

    q.push({temp, dist + 1});
    return -1;
}

int main() {
    int a, b, cnt = -1;
    cin >> a >> b;

    q.push({b, 0});

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        int val = cur.first, dist = cur.second;
        q.pop();

        cnt = bfs(val, dist, a);

        if (cnt != -1) {
            break;
        }
    }

    if (ans.size() > cnt) {
        cout << ans.size() << endl;
    } else {
        cout << cnt << endl;
    }

    if (ans.size() > 0) {
        for (int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i] << " ";
        }
    }

    return 0;
}

