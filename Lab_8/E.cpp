#include <iostream>
#include <vector>
using namespace std;

vector<char> unhashing(const long long *h, int n) {
    long long p[n];
    p[0] = 1;

    for (int i = 1; i < n; i++) {
        p[i] = (p[i - 1] * 2);
    }

    vector<char> ans(n);

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            ans[i] = static_cast<char>((h[i] / p[i]) + 97);
        } else {
            ans[i] = static_cast<char>(((h[i] - h[i - 1]) / p[i]) + 97);
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    long long h[n];

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    vector<char> ans = unhashing(h, n);

    for (int i = 0; i < n; i++) {
        cout << ans[i];
    }

    return 0;
}
