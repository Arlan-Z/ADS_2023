#include <iostream>
#include <vector>
using namespace std;

vector<size_t> computeLPS(string pattern) {
    size_t n = pattern.size();
    vector<size_t> lps(n, 0);
    size_t len = 0;
    
    for (size_t i = 1; i < n; ) {
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

bool isFind(string text, string pattern) {
    size_t m = text.size();
    size_t n = pattern.size();
    vector<size_t> lps = computeLPS(pattern + "#" + text);
    
    for (size_t i = 0; i < m; i++) {
        if (lps[n + 1 + i] == n) {
            return true;
        }
    }
    
    return false;
}

int main() {
    string text, pattern;
    cin >> text >> pattern;
    
    size_t cnt = 1;
    string concatenatedString = text;
    
    while (concatenatedString.size() < pattern.size()) {
        concatenatedString += text;
        cnt++;
    }
    
    if (isFind(concatenatedString, pattern)) {
        cout << cnt;
    } else if (isFind(concatenatedString + text, pattern)) {
        cout << cnt + 1;
    } else {
        cout << -1;
    }

    return 0;
}

