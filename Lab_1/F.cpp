#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    vector <int> Primes;
    Primes.push_back(2);
    
    int num = 2;
    while(Primes.size() <= n)
    {
        for(int i = 0; i < Primes.size(); i++)
        {
            if(num % Primes[i] == 0)
            {
                break;
            }
            if(i == Primes.size()- 1)
            {
                Primes.push_back(num);
                break;
            }
        }
        
        num++;
    }
    cout << Primes[n - 1];
    
}