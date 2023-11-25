#include <iostream>
#include <vector>
using namespace std;

vector<size_t> computeLPS(const string& s) {
    size_t n = s.size();
    vector<size_t> lps(n);
    lps[0] = 0;

    for (size_t i = 1, j = 0; i < n; ) {
        if (s[i] == s[j]) {
            j++;
            lps[i] = j;
            i++;
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

int main() {
    string text, pattern;
    cin >> text >> pattern;

    string s = pattern + '#' + text;
    vector<size_t> ans = computeLPS(s);

    int cnt = 0;
    string res = "";

    for (size_t i = 0; i < ans.size(); i++) {
        if (ans[i] == pattern.size()) {
            cnt++;
            res += to_string(i - 2 * pattern.size() + 1) + " ";
        }
    }

    cout << cnt << endl << res;
    return 0;
}


