#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int n, f; cin >> n >> f;
    
    int nums[n];
    int buf[4];
    
    for(int i = 0; i < n;i++)
    {
        for(int j = 0; j < 4; j++) cin >> buf[j];
        nums[i] = *max_element(buf, buf + 4);
    }
    
    sort(nums, nums + n);
    int max = n - 1, min = 0;
    while(max >= min)
    {
        int mid = (max + min) / 2;
        
        if(mid >= f) max = mid - 1;
        else min = mid + 1;
    }
    
    cout << nums[min - 1];
    return 0;
}
