#include<iostream>
#include<vector>
using namespace std;



void back(int n, int ind, vector<int>& sol) 
{
    if(n == ind) 
    {
        bool start = true;
        for(int i = 0; i < n; ++i) 
        {
            if(start)  
            {
                cout << sol[i];
                start = false;
            }
            else cout << ' ' << sol[i];
        }
        cout << endl;
    }
    else 
    {
        sol[ind] = 0;
        back(n, ind + 1, sol);
        sol[ind] = 1;
        back(n, ind + 1, sol);
    }
}


int main() 
{
    int n;
    cin >> n;
    vector<int>sol(n);
    back(n, 0, sol);
}