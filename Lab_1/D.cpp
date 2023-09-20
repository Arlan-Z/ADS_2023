#include <deque>
#include <iostream>

using namespace std;

int main()
{
    deque <char> d;
    string s; cin >> s;
    for(int i = 0; i < s.length(); i++)
    {
        d.push_back(s[i]);
    }
    
    int n = s.length();
    
    int i = 0;
    while(i < n)
    {
        if(d.front() == d.back())
        {
            d.pop_front();
            d.pop_back();
            i = 0;
            n -= 2;
            continue;
        }
        else
        {
            i++;
            d.push_back(d.front());
            d.pop_front();
        }
        
    }
    
    if(n == 0) cout << "YES";
    else cout << "NO";

    return 0;
}