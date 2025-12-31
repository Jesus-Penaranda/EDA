#include<iostream>
#include<set>

using namespace std;

int main() 
{
    string pa;
    set<string> words;
    auto it = words.begin();
    while(cin >> pa and pa != "END") 
    {
        words.insert(pa);
        if (words.size()%2 != 0) 
        {
            if (pa > *it)
            ++it;
            
        }
        else 
        {
            if (pa < *it)
            --it;
            
        }
        cout << *it << endl;
    }
}