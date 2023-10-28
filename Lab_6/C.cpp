#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> points(N);
    for(int i = 0; i < N; i++) {
        cin >> points[i];
    }

   
    sort(points.begin(), points.end());

    
    int min_diff = INT_MAX;
    for(int i = 1; i < N; i++) {
        min_diff = min(min_diff, points[i] - points[i-1]);
    }

   
    for(int i = 1; i < N; i++) {
        if(points[i] - points[i-1] == min_diff) {
            cout << points[i-1] << " " << points[i] << " ";
        }
    }
    cout << endl;
    
    return 0;
}

// I H A
 
