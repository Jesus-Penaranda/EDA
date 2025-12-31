// Problem that returns the position of x in the vector. Return -1 
// if the value is not found or if left > right.

#include <iostream>
#include <vector>
using namespace std;


int position(double x, const vector<double>& v, int left, int right) 
{
    int m = (left + right) / 2;
    if ((left > right)) return -1;
    else if (x == v[m]) return m;
    else 
    {
        if (x > v[m]) return position(x,v, m + 1, right);
        else return position(x,v, left, m - 1);
    }
}

