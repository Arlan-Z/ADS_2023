#include <iostream>
#include <climits>

using namespace std;

int findBlock(int nums[], int find, int max, int min)
{
    if(max > min)
    {
         int index = (max + min) / 2;
        
        if(nums[index] > find) return findBlock(nums, find, index - 1, min);
        if(nums[index] < find) return findBlock(nums, find, max, index + 1);
        
        return index;
    }
    
    if(nums[max] >= find && max >= 0) return max;
    else return max + 1;
    
}    

int main()
{
    int n,m; cin >> n >> m;
    int lines;
    int cnt = 0;
    int block[n];
    for(int i = 0; i < n; i++)
    {
        cin >> lines;
        cnt += lines;
        block[i] = cnt;
    }
    
    //for(int i = 0; i < n; i++) cout << block[i] << " ";

    
    for(int i = 0; i < m; i++)
    {
        int a; cin >> a;
        cout << findBlock(block, a, n - 1, 0) + 1 << endl;
    }
}
