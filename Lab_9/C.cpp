#include <iostream>
#include <vector>
using namespace std;

vector<size_t> computeLPS(const string& s) {
    size_t n = s.size();
    vector<size_t> lps(n, 0);

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

int findShiftAmount(const string& text, const string& changed_text) {
    string concatenatedString = changed_text + '#' + text + text;
    vector<size_t> lps = computeLPS(concatenatedString);

    for (int i = lps.size() - 1; i >= 0; i--) {
        if (lps[i] == changed_text.size()) {
            return concatenatedString.size() - i - 1;
        }
    }

    return -1;
}

int main() {
    string text, changed_text;
    cin >> text >> changed_text;

    int shiftAmount = findShiftAmount(text, changed_text);

    if (shiftAmount != -1) {
        cout << shiftAmount;
    } else {
        cout << -1;
    }

    return 0;
}

