#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<size_t, size_t> occurrences;
size_t countOccurrences = 0;

void hashAndCount(string s, string t) {
    size_t n = s.size(), m = t.size();
    long long h[n], p[n], q = 1e9 + 7, hOfPattern = 0;
    p[0] = 1;

    for (size_t i = 1; i < n; i++) {
        p[i] = (p[i - 1] * 31) % q;
    }

    for (size_t i = 0; i < n; i++) {
        h[i] = ((s[i] - int('a') + 1) * p[i]) % q;
        if (i > 0) {
            h[i] = (h[i] + h[i - 1]) % q;
        }
    }

    for (size_t i = 0; i < m; i++) {
        hOfPattern = (hOfPattern + ((t[i] - int('a') + 1) * p[i]) % q) % q;
    }

    for (size_t i = 0; i + m - 1 < n; i++) {
        long long d = h[i + m - 1];

        if (i > 0) {
            d = (d - h[i - 1] + q) % q;
        }

        if (d == (hOfPattern * p[i]) % q) {
            occurrences[i]++;
            if (occurrences[i] == 2) {
                countOccurrences++;
            }
        }
    }
}

int main() {
    string target;
    vector<string> sourceStrings;

    for (int i = 0; i < 2; i++) {
        string input;
        cin >> input;
        sourceStrings.push_back(input);
    }

    cin >> target;

    for (int i = 0; i < 2; i++) {
        hashAndCount(sourceStrings[i], target);
    }

    cout << countOccurrences;

    return 0;
}

