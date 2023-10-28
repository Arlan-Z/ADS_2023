#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    
    int freq[26] = {0};

    
    for (char c : s) {
        freq[c - 'a']++;
    }

  
    string sortedString = "";
    for (int i = 0; i < 26; i++) {
        while (freq[i] > 0) {
            sortedString += (char)(i + 'a');
            freq[i]--;
        }
    }

    cout << sortedString << endl;
    return 0;
}


