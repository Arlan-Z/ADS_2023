#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<char> letters(n);
    for (int i = 0; i < n; i++) {
        cin >> letters[i];
    }

    char givenLetter;
    cin >> givenLetter;

    for (int i = 0; i < n; i++) {
        if (letters[i] > givenLetter) {
            cout << letters[i] << endl;
            return 0;
        }
    }


    cout << letters[0] << endl;

    return 0;
}


