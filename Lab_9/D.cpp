#include <iostream>
#include <vector>
using namespace std;

vector<size_t> computeLPS(const string& s) {
    size_t n = s.size();
    vector<size_t> lps(n);
    lps[0] = 0;

    for (size_t i = 1, j = 0; i < n; ) {
        if (s[i] == s[j] || s[i] - s[j] == 32) {
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

void print(const vector<string>& v) {
    for (const string& str : v) {
        cout << str << endl;
    }
}

int main() {
    string text;
    cin >> text;

    int n;
    cin >> n;

    vector<pair<string, size_t>> towns(n);
    size_t mx = 0;

    for (int i = 0; i < n; i++) {
        string town;
        cin >> town;

        string pattern = town + '#' + text;
        vector<size_t> res = computeLPS(pattern);
        size_t mxlen = res.back(); // Last element of the LPS array
        mx = max(mx, mxlen);
        towns[i] = make_pair(town, mxlen);
    }

    if (mx == 0) {
        cout << 0;
        return 0;
    }

    vector<string> ans;

    for (int i = 0; i < towns.size(); i++) {
        if (towns[i].second == mx) {
            ans.push_back(towns[i].first);
        }
    }

    cout << ans.size() << endl;
    print(ans);

    return 0;
}


