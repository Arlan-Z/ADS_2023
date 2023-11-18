#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countPatternOccurrences(string inputText, string pattern) {
    size_t n = inputText.size(), m = pattern.size();
    long long h[n], p[n], q = 1e9 + 7, h_t = 0;
    p[0] = 1;
    int count = 0;

    for (size_t i = 1; i < n; i++) {
        p[i] = (p[i - 1] * 31) % q;
    }

    for (size_t i = 0; i < n; i++) {
        h[i] = ((inputText[i] - int('a') + 1) * p[i]) % q;
        if (i > 0) {
            h[i] = (h[i] + h[i - 1]) % q;
        }
    }

    for (size_t i = 0; i < m; i++) {
        h_t = (h_t + ((pattern[i] - int('a') + 1) * p[i]) % q) % q;
    }

    for (size_t i = 0; i + m - 1 < n; i++) {
        long long d = h[i + m - 1];
        if (i > 0) {
            d = (d - h[i - 1] + q) % q;
        }
        if (d == (h_t * p[i]) % q) {
            count++;
        }
    }

    return count;
}

int main() {
    bool run = true;

    while (run) {
        int numPatterns, maxOccurrences = -1;
        cin >> numPatterns;

        if (numPatterns == 0) {
            run = false;
            break;
        }

        vector<pair<string, int>> patternOccurrences;
        string patterns[numPatterns];

        for (int i = 0; i < numPatterns; i++) {
            cin >> patterns[i];
        }

        string inputText;
        cin >> inputText;

        for (int i = 0; i < numPatterns; i++) {
            int occurrences = countPatternOccurrences(inputText, patterns[i]);

            if (occurrences > maxOccurrences) {
                maxOccurrences = occurrences;
            }

            patternOccurrences.push_back(make_pair(patterns[i], occurrences));
        }

        cout << maxOccurrences << endl;

        for (auto it : patternOccurrences) {
            if (it.second == maxOccurrences) {
                cout << it.first << endl;
            }
        }
    }

    return 0;
}

