#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void balancedBSTShuffle(vector<int> &arr, vector<int> &result, int start, int end, int &index) {
    if (start > end) return;
    
    int mid = start + (end - start) / 2;
    result[index++] = arr[mid];

    balancedBSTShuffle(arr, result, start, mid - 1, index);
    balancedBSTShuffle(arr, result, mid + 1, end, index);
}

int main() {
    int N;
    cin >> N;
    N = (1 << N) - 1; 

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<int> result(N);
    int index = 0;
    
    balancedBSTShuffle(arr, result, 0, N - 1, index);

    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }

    return 0;
}



