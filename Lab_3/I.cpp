#include <iostream>
#include <climits>

using namespace std;

int findCoord(int nums[], int findNum, int max, int min)
{
    if(max >= min)
    { 
        
        int index = (min + max) / 2;
        
        if(nums[index] > findNum) return findCoord(nums, findNum, index - 1, min);
        if(nums[index] < findNum) return findCoord(nums, findNum, max, index + 1);
            
        return index;  

    }
    return -1;
}

int main()
{
    int n; cin >> n;
    int nums[n];
    for(int i = 0; i < n; i++) cin >> nums[i];
    int f; cin >> f;
    
    int check = findCoord(nums, f, n, 0);
    
    check != -1 ? cout << "Yes" : cout << "No";
}
