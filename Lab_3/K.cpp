#include <climits>
#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    int f; cin >> f;
    int nums[n];
    int prefix[n] = {0};
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
        prefix[i + 1] = prefix[i] + nums[i];
    }
    int cnt = INT_MAX;
    int newcnt = INT_MAX;
    
    int min = 0;
    int max = 0;
    for(int i = 0; i < n; i++)
    {
        max ++;
        
        while((prefix[max] - prefix[min]) >= f)
        {
            newcnt = max - min;
            if(newcnt < cnt) cnt = newcnt;
            min ++;
        }
    }
    
    
    cout << cnt;
    return 0;
}
