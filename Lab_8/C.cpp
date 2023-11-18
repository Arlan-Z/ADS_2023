#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> tape;

void hashAndMark(string inputString, string pattern) {
    size_t n = inputString.size(), m = pattern.size();
    long long h[n], p[n], q = 2147483647, h_t = 0;
    p[0] = 1;

    for (size_t i = 1; i < n; i++) {
        p[i] = (p[i - 1] * 31) % q;
    }

    for (size_t i = 0; i < n; i++) {
        h[i] = ((inputString[i] - 'a' + 1) * p[i]) % q;
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

        if (d == (h_t * p[i]) % q && pattern == inputString.substr(i, m)) {
            for (size_t j = i; j < i + m; j++) {
                tape[j]++;
            }
        }
    }
}

int main() {
    string inputString;
    int numOfPatterns;
    cin >> inputString >> numOfPatterns;

    tape.resize(inputString.size());

    for (int i = 0; i < numOfPatterns; i++) {
        string pattern;
        cin >> pattern;
        hashAndMark(inputString, pattern);
    }

    bool isEveryElementMarked = all_of(tape.begin(), tape.end(), [](int mark) { return mark > 0; });

    if (isEveryElementMarked) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

