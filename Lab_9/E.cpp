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
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int m;
        cin >> m;

        string res = s;
        vector<size_t> ans = computeLPS(res);

        if (res.size() == 1) {
            cout << res.size() * m << endl;
        } else {
            int patternSize = ans.back(); // Last element of the LPS array
            cout << (res.size() - patternSize) * (m - 1) + s.size() << endl;
        }
    }

    return 0;
}



