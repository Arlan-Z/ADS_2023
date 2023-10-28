#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> first(n), second(m);

    for (int i = 0; i < n; ++i) {
        cin >> first[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> second[i];
    }

    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    int i = 0, j = 0;

    while (i < n && j < m) {
        if (first[i] == second[j]) {
            cout << first[i] << " ";
            i++;
            j++;
        } else if (first[i] < second[j]) {
            i++;
        } else {
            j++;
        }
    }

    cout << endl;
    return 0;
}

