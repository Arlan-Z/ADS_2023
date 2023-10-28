#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

 
bool customSort (const vector < int >&a, const vector < int >&b)
{
  
int sumA = accumulate (a.begin (), a.end (), 0);
  
int sumB = accumulate (b.begin (), b.end (), 0);
  
 
if (sumA != sumB)
    {
      
return sumA > sumB;
    
}
  
return a < b;

}


 
int
main ()
{
  
int n, m;
  
cin >> n >> m;
  
 
vector < vector < int >>rows (n, vector < int >(m));
  
for (int i = 0; i < n; i++)
    {
      
for (int j = 0; j < m; j++)
	{
	  
cin >> rows[i][j];
    
} 
} 
 
sort (rows.begin (), rows.end (), customSort);

 
for (const auto & row:rows)
    {
    
for (const auto & element:row)
	{
	  
cout << element << " ";
	
} 
cout << endl;
    
} 
return 0;

}


 
 
 
