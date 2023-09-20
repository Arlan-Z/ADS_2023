#include <deque>
#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    deque<int> Deck;
    for(int i = 0; i < T; i++)
    {
        int a;
        cin >> a;
        
        Deck.push_front(a);
        for(int j = a - 1; j > 0; j -- )
        {
               Deck.push_front(j);
               for(int k = 1; k <= j; k++)
               {
                   int buf = Deck.back();
                   Deck.push_front(buf);
                   Deck.pop_back();
               }
        }
    
        while(!Deck.empty())
        {
            cout << Deck.front() << " ";
            Deck.pop_front();
        }
        cout << endl;
    }
}
