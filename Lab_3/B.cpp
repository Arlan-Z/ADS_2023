#include <iostream>
using namespace std;

bool isPossible(int arr[], int n, long long x, int k) {
    long long cnt = 0;
    long long sum = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] > x) return false;
        else if (sum + arr[i] > x) {
            sum = arr[i];
            cnt++;
        } else {
            sum += arr[i];
        }
    }
    
    cnt++;
    return cnt <= k;
}

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    long long left = 0;
    long long right = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        right += a[i];
    }
    
    long long ans = 0;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        
        if (isPossible(a, n, mid, k)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << ans;
    return 0;
}


