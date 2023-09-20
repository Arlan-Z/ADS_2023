#include <deque>
#include <iostream>

using namespace std;

int main()
{
    deque<int> Boris;
    deque<int> Nursik;
    
    int Moves = 0;
    for(int i = 0; i < 5; i++)
    {
        int a; cin >> a;
        Boris.push_back(a);
    }
    for(int i = 0; i < 5; i++)
    {
        int a; cin >> a;
        Nursik.push_back(a);
    }
    while(!Nursik.empty() && !Boris.empty())
    {
        if((Nursik.front() > Boris.front() || (Nursik.front() == 0 && Boris.front() == 9)) && !(Nursik.front() == 9 && Boris.front() == 0) )
        {
            Nursik.push_back(Boris.front());
            Nursik.push_back(Nursik.front());
            
            Boris.pop_front();
            Nursik.pop_front();
        }
        else
        {
            
            Boris.push_back(Boris.front());
            Boris.push_back(Nursik.front());
            
            Nursik.pop_front();
            Boris.pop_front();
        }
        
        Moves ++;
        if(Moves > 1000000)
        {
            cout << "blin nichya" << endl;
            return 0;
        
        }
    }
    
    
    if(Nursik.empty())
    {
        cout << "Boris " << Moves;
    }
    else cout << "Nursik " << Moves;
    
}