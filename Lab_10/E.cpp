#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int b;
            cin >> b;
            matrix[i][j] = b;
        }
    }

    while (q--) {
        int e1, e2, e3;
        cin >> e1 >> e2 >> e3;
        e1--; e2--; e3--;

        int check = 0;
        if (matrix[e1][e2] == 1) {
            check++;
        }
        if (matrix[e1][e3] == 1) {
            check++;
        }
        if (matrix[e2][e3] == 1) {
            check++;
        }

        if (check == 3) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}


