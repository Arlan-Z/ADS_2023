#include <climits>
#include <iostream>
#include <algorithm>


using namespace std;

int main()
{
    int n; cin >> n;
    int nums[n];
    for(int i = 0; i < n; i++) cin >> nums[i];
    sort(&nums[0], &nums[n]);
    
    int a; cin >> a;
    for(int i = 0; i < a; i++)
    {
        int b; cin >> b;
        int sum = 0;
        int cnt = 0;
        for(int j = 0; j < n; j++)
        {
            if(nums[j] > b) break;
            sum += nums[j];
            cnt ++;
        }
        cout << cnt << " " << sum << endl;
    }
    
        
    return 0;
}
