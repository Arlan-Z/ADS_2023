#include <bits/stdc++.h>
using namespace std;

long long binary_search(long long x, long long a[], long long n, int lr) {
    long long left = 0;
    long long right = n - 1;
    long long mid; 
    while (left <= right) {
        mid = left + (right - left) / 2;

        if (a[mid] == x) {
            return mid;
        }
        else if (a[mid] < x) {
            left = mid + 1;
        }
        else if (a[mid] > x) {
            right = mid - 1;
        }
    }
    if (lr == 0) { 
        return left;
    }
    if (lr == 1) { 
        return right;
    }
}

long long index(long long left, long long right, long long a[], long long n) {
    return binary_search(right, a, n, 1) - binary_search(left, a, n, 0) + 1;
}

int main() {    
    long long n, q;
    cin >> n >> q;
    
    long long a[n];
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    for (long long i = 0; i < q; i++) {
        long long l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        if (l1 <= l2 && r2 <= r1) {
            cout << index(l1, r1, a, n) << endl;
        }
        else if (l2 <= l1 && r1 <= r2) {
            cout << index(l2, r2, a, n) << endl;
        }        
        else if (r2 >= l1 && r1 >= r2 && l1 >= l2) {
            cout << index(l2, r1, a, n) << endl;
        }
        else if (r1 >= l2 && r2 >= r1 && l2 >= l1) {
            cout << index(l1, r2, a, n) << endl;
        }
        else {
            cout << index(l1, r1, a, n) + index(l2, r2, a, n) << endl;
        }
    }

    return 0;
}


