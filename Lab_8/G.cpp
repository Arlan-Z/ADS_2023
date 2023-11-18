#include <iostream>
using namespace std;

int countOccurrences(string fullString, string pattern) {
    size_t n = fullString.size(), m = pattern.size();
    long long cnt = 0, h[n], p[n], q = 1e7 + 7, h_t = 0;
    p[0] = 1;

    for (size_t i = 1; i < n; i++) {
        p[i] = (p[i - 1] * 31) % q;
    }

    for (size_t i = 0; i < n; i++) {
        h[i] = ((fullString[i] - 'a' + 1) * p[i]) % q;
        if (i > 0) {
            h[i] = (h[i] + h[i - 1]) % q;
        }
    }

    for (size_t i = 0; i < m; i++) {
        h_t = (h_t + ((pattern[i] - 'a' + 1) * p[i]) % q) % q;
    }

    for (size_t i = 0; i + m - 1 < n; i++) {
        long long d = h[i + m - 1];
        if (i > 0) {
            d = (d - h[i - 1] + q) % q;
        }

        if (d == (h_t * p[i]) % q) {
            if (pattern == fullString.substr(i, m)) {
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    int n, l, r;
    string s;
    cin >> s >> n;

    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        cout << countOccurrences(s, s.substr(l - 1, r - l + 1)) << endl;
    }

    return 0;
}
