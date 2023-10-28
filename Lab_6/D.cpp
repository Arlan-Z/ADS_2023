#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;


int convertDateToInt(const string& date) {
    int day = stoi(date.substr(0, 2)); // stoi converting string to int
    int month = stoi(date.substr(3, 2));
    int year = stoi(date.substr(6, 4));
    return year * 10000 + month * 100 + day;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, string>> dates;
    for(int i = 0; i < n; i++) {
        string date;
        cin >> date;
        dates.push_back({convertDateToInt(date), date});
    }

    // Sort by the integer representation.
    sort(dates.begin(), dates.end());

    for(auto& p: dates) {
        cout << p.second << endl;
    }

    return 0;
}
