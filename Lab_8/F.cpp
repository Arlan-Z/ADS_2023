#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e15 + 7;
const ll BASE = 30;

string inputString;
unordered_map<ll, bool> hashSet;
vector<ll> substrings;

void generateHashes(string s) {
    for (int i = 0; i < s.size(); i++) {
        ll hashValue = 0, power = 1;
        
        for (int j = i; j < s.size(); j++) {
            hashValue = (hashValue + (power * (s[j] - 'a' + 1)) % MOD) % MOD;

            if (hashSet.find(hashValue) == hashSet.end()) {
                substrings.push_back(hashValue);
                hashSet[hashValue] = true;
            }

            power = (power * BASE) % MOD;
        }
    }
}

int main() {
    cin >> inputString;
    generateHashes(inputString);
    cout << substrings.size();

    return 0;
}
