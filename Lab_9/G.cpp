#include <iostream>
#include <vector>
using namespace std;

vector<size_t> computeLPS(const string& s) {
    size_t n = s.size();
    vector<size_t> lps(n);

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
    string text;
    cin >> text;

    vector<size_t> ans = computeLPS(text);

    cout << text.size() - ans.back() << endl;

    return 0;
}


