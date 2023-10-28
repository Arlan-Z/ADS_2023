#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, string> nicknames;
    map<string, string> reverseMap; 

    while (n--) {
        string oldNick, newNick;
        cin >> oldNick >> newNick;

       
        if (reverseMap.find(oldNick) == reverseMap.end()) {
            nicknames[oldNick] = newNick;
            reverseMap[newNick] = oldNick;
        } else {
         
            string original = reverseMap[oldNick];
            nicknames[original] = newNick;
            reverseMap[newNick] = original;
            reverseMap.erase(oldNick);  
        }
    }

    cout << nicknames.size() << endl;
    for (auto& kv : nicknames) {
        cout << kv.first << " " << kv.second << endl;
    }

    return 0;
}

