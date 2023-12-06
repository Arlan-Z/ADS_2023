#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

char grid[MAX_SIZE][MAX_SIZE];
int rows, cols;

void dfs(int i, int j) {
    if (i < 0 || j < 0 || grid[i][j] == '0' || i >= rows || j >= cols) {
        return;
    }
    grid[i][j] = '0';
    dfs(i, j + 1);
    dfs(i, j - 1);
    dfs(i + 1, j);
    dfs(i - 1, j);
}

int main() {
    int count = 0;

    cin >> rows >> cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '1') {
                dfs(i, j);
                count++;
            }
        }
    }

    cout << count;

    return 0;
}




