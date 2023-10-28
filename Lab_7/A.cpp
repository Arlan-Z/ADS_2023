#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(const string &a, const string &b) {
    return a.size() < b.size();
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); 

    for (int t = 0; t < T; ++t) {
        string line;
        getline(cin, line);
        vector<string> words;
        string word;

        for (char c : line) {
            if (c == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
            } else {
                word += c;
            }
        }
        if (!word.empty()) {
            words.push_back(word);
        }

        stable_sort(words.begin(), words.end(), compare);

        for (const string &w : words) {
            cout << w << " ";
        }
        cout << endl;
    }

    return 0;
}
