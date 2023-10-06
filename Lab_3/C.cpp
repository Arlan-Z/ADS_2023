#include <iostream>

using namespace std;

int main()
{
    int n, l; cin >> n >> l;
    int find[n];
    for(int i = 0; i < n; i++) cin >> find[i];
    int nums[l][4];
    for(int i = 0; i < l; i++) 
    {
        for(int j = 0; j < 4; j++) cin >> nums[i][j];
    }
    
    int index = 0;
    while(index < l)
    {
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(find[i] >= nums[index][0] && find[i] <= nums[index][1]) 
            {
                cnt ++;
                continue;
            }
            if(find[i] >= nums[index][2] && find[i] <= nums[index][3]) cnt ++;
        }
        
        cout << cnt << endl;
        index ++;
    }
    
    return 0;
}
