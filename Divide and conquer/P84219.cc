#include <iostream>
#include <vector>
using namespace std;

int first_occurrence(double x, const vector<double>& v) 
{

    int left = 0, right = v.size() - 1;
    int result = -1; 
    
    while (left <= right) 
    {
        int m = (left + right) / 2; 
        if (v[m] == x) 
        {
            result = m;      
            right = m - 1;  
        } 
        else if (v[m] > x) right = m - 1;  
        else left = m + 1;   
    }
    return result; 
}
