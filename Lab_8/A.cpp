#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>

using namespace std;

const long long MOD = 1e9 + 7;
const long long P = 11;

long long calculateHash(const string& s) {
    long long h = 0;
    for (long long i = s.size() - 1; i >= 0; --i) {
        h = (h * P % MOD + (s[i] - '0')) % MOD;
    }
    return h;
}

int main() {
    long long n;
    cin >> n;

    unordered_set<string> hashes;
    vector<pair<string, string>> a(2 * n);

    // Считывание строк, вычисление их хешей и добавление в множество
    for (long long i = 0; i < 2 * n; ++i) {
        string s;
        cin >> s;
        a[i] = {get_hash(s), s};
        hashes.insert(s);
    }

    int j = 0;

    // Поиск уникальных хешей и вывод
    for (long long i = 0; i < 2 * n && j < n; ++i) {
        auto it = hashes.find(a[i].first);
        if (it != hashes.end()) {
            cout << "Hash of string \"" << a[i].second << "\" is " << a[i].first << "\n";
            ++j;
            hashes.erase(it);  // Избегаем повторных выводов для одинаковых хешей
        }
    }

    return 0;
}


