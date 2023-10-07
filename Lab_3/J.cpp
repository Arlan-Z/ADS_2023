#include <algorithm>
#include <iostream>

using namespace std;


bool check(int nums[], int c, int t, int n)
{
    int cnt = 0;
    if(c == 0) return false;
    for(int i = 0; i < n; i++)
    {
        cnt += nums[i] / c;
        if(nums[i] % c != 0) cnt++;
    }
    
    return cnt <= t;
}

int main()
{
    int n; cin >> n;
    int l; cin >> l;
    
    int nums[n];
    for(int i =0; i < n; i++) cin >> nums[i];
    //sort(&nums[0], &nums[n]);
    //for(int i =0; i < n; i++) cout <<  nums[i] << " ";
    //cout << endl;
    int min = 0;
    int max = *max_element(nums, nums + n);
    while(max >= min)
    {
        int med = (max + min) / 2;
        
        if(check(nums, med, l, n)) 
        {
            //cout << check(nums, med, l, n) << " ";
            //cout << med << " ";
            //cout << "worked" << endl;
            max = med - 1;
        }
        else min = med + 1;
    }
    cout << min;

    return 0;
}
