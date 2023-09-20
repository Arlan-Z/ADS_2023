#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    vector <int> Primes;
    vector <int> SuperPrimes;
    Primes.push_back(2);

    
    
    int num = 2;

    while(SuperPrimes.size() < n)
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
                for(int i = 0; i < Primes.size(); i++)
                {
                    
                    if(Primes.size() == Primes[i])
                    {
                        SuperPrimes.push_back(Primes.back());
                        break;
                    }
                    
                }
                break;
            }
            
        }
        
        num ++;
        
        
        

        
        
    }
    cout << SuperPrimes[n - 1];
    
}