#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string longest_common_substring(const vector<string>& strings) {
    if (strings.empty()) return "";

    int minLen = min_element(strings.begin(), strings.end(), [](const string& a, const string& b) {
        return a.length() < b.length();
    })->length();

    string longest_substring = "";
    
    for (int len = minLen; len > 0; --len) {
        for (int i = 0; i <= minLen - len; ++i) {
            string substring = strings[0].substr(i, len);
            bool presentInAll = all_of(strings.begin() + 1, strings.end(), [&](const string& s) {
                return s.find(substring) != string::npos;
            });

            if (presentInAll) {
                return substring;
            }
        }
    }

    return longest_substring;
}

int main() {
    int K;
    cin >> K;
    vector<string> strings(K);

    for (int i = 0; i < K; ++i) {
        cin >> strings[i];
    }

    string result = longest_common_substring(strings);
    cout << result << endl;

    return 0;
}
