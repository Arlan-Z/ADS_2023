#include <iostream>
#include <vector>
using namespace std;

vector<size_t> computeLPS(const string& pattern) {
    size_t n = pattern.size();
    vector<size_t> lps(n, 0);

    for (size_t i = 1, len = 0; i < n; ) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

bool isPatternRepeated(const string& pattern, int n, const string& text) {
    string concatenatedString = pattern + '#' + text;
    vector<size_t> lps = computeLPS(concatenatedString);

    int cnt = 0;
    for (size_t i = 0; i < lps.size(); i++) {
        if (lps[i] == pattern.size()) {
            cnt++;
        }
    }

    return cnt >= n;
}

int main() {
    string pattern, text;
    int n;
    cin >> pattern >> n >> text;

    if (isPatternRepeated(pattern, n, text)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
