#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    char c;
    deque<int> Nums;
    vector<int> Ans;
    while(c != '!')
    {
        cin >> c;
        if(c == '+' || c == '-')
        {
            int a;
            cin >> a;
            if ( c == '+') Nums.push_front(a);
            else Nums.push_back(a);
            
            continue;
        }
        if(c == '*') 
        {
            if(Nums.size() <= 0) Ans.push_back(-1);
            else
            {
            Ans.push_back(Nums.front() + Nums.back());
            Nums.pop_front();
            if(!Nums.empty()) Nums.pop_back();
            }
            
            continue;
        }
        
    }
    for(int i = 0; i < Ans.size(); i ++)
    {
        if(Ans[i] == -1) cout << "error" << endl;
        else cout << Ans[i] << endl;
    }
}