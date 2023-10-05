#include <iostream>
#include <climits>

using namespace std;

int findCoord(int nums[], int findNum, int max, int min)
{
    if(max >= min)
    { 
        
        int index = (min + max) / 2;
        
        if(nums[max] < nums[min])
        {
            if(nums[index] > findNum) return findCoord(nums, findNum, max, index + 1);
            if(nums[index] < findNum) return findCoord(nums, findNum, index - 1, min);
            
            return index;
        }
        
        else
        {
            if(nums[index] > findNum) return findCoord(nums, findNum, index - 1, min);
            if(nums[index] < findNum) return findCoord(nums, findNum, max, index + 1);
            
            return index;  
        }
    }
    return -1;
}

int main()
{
    int t; cin >> t;
    int find[t];
    int coord[t][2];
    for(int i = 0; i < t; i++) 
    {
        cin >> find[i];
        coord[i][0] = -1; 
    }
    
    
    int n,m; cin >> n >> m;
    int nums[n][m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> nums[i][j];
        }
    }
    
    int index = 0;
    while(index < n)
    {
        for(int i = 0; i < t; i++)
        {
            if(find[i] == INT_MIN) continue;
            
            int xy = findCoord(nums[index], find[i], m - 1, 0);
            if(xy == -1) continue;
            
            coord[i][0] = index;
            coord[i][1] = xy;
            find[i] = INT_MIN;
        }
        
        index++;
    }
    
    for(int i = 0; i < t; i++)
        {
            cout << coord[i][0] << " ";
            coord[i][0] == -1 ? cout << endl : cout << coord[i][1] << endl;
        }
    
}
