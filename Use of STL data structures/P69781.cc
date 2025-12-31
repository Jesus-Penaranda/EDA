#include<map>
#include<iostream>

using namespace std;

int main() 
{
    int x,y,n;
    while (cin >> x >> y >> n) 
    {
        map<int,int> numbers;
        bool found = false;
        while (n <= 100000000 and not found) 
        {
            numbers[n]++;

            if (numbers[n] >= 2) found = true;
            else 
            {
                if (n%2 == 0) n = n/2 + x;
                else n = 3*n + y;
            }

        }
        int trobat = n;
        int cicle = 0;
        if (n > 100000000) cout << n << endl;
        else 
        {
            while (numbers[trobat] != 3) 
            {
                ++cicle;
                if (n%2 == 0) n = n/2 + x;
                else n = 3*n + y;
                numbers[n]++;
            }
            cout << cicle << endl;
        }
        
            
        
    }
}