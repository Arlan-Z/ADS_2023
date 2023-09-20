#include <deque>
#include <iostream>

using namespace std;

int main()
{
    string Text1;
    string Text2;
    deque<char> A;
    deque<char> B;
    cin >> Text1 >> Text2;
    
    for(int i = 0; i < Text1.length(); i++)
    {
        if( Text1[i] == '#' && !A.empty()) A.pop_back() ;
        else A.push_back(Text1[i]);
    }
    for(int i = 0; i < Text2.length(); i++)
    {
        if(Text2[i] == '#' && !B.empty()) B.pop_back();
        else B.push_back(Text2[i]);
    }
    if(A == B) cout << "Yes";
    else cout << "No";
}
