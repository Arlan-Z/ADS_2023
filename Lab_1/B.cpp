#include <iostream>

using namespace std;

int main()
{
    int Count;
    cin >> Count;
    int Nums[Count];
    int Inds[Count];
    for(int i = 0; i < Count; i++)
    {
        int Buf = -1;
        cin >> Nums[i];
        for(int j = i - 1; j < i; j --)
        {
            if(j < 0) break;
            if(Nums[i] >= Nums[j])
            {
                Buf = Nums[j];
                break;
            }
        }
        Inds[i] = Buf;
    }
    
    for(int i = 0; i < Count; i++)
    {
        cout << Inds[i] << " ";
    }

    return 0;
}
