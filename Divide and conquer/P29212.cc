#include <iostream>
#include <vector>
using namespace std;

int exponente(int k, int base, int mod) 
{
    if (k == 0) return 1;
    if (k == 1) return base%mod;
    else 
    {
        int num = exponente(k/2, base, mod);
        if (k%2 == 0) return (num*num)%mod;
        else return (base*(num*num%mod))%mod;
    }
}

int main()
{
    int num, k, mod;
    while(cin >> num >> k >> mod) 
    {
        cout << exponente(k, num, mod) << endl;
    }

}

