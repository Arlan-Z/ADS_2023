
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    string s; cin >> s;
    
    int S = 0;
    int K = 0;
    
    
    cycle:
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '0') continue;
        
        if(s[i] == 'K')
        {
            if(K > 0)
            {
                K--;
                s[i] = '0';
                continue;
            }
            
            S++;
            continue;
        }
        if(s[i] == 'S')
        {
            if(S > 0)
            {
                S--;
                s[i] = '0';
                continue;
            }
            
            K++;
            continue;
        }
    }

if(count(s.begin(), s.end(), 'K') != 0 && count(s.begin(), s.end(), 'S') != 0) goto cycle;

if(count(s.begin(), s.end(), 'K') == 0) cout << "SAKAYANAGI";
else cout << "KATSURAGI";

    return 0;
}
