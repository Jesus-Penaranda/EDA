#include<map>
#include<iostream>

using namespace std;

int main() 
{
    string ins;
    map<string, int> paraules;
    while(cin >> ins) 
    {
        string paraula;
        if (ins == "minimum?") 
        {
            if(paraules.empty()) cout << "indefinite minimum";
            else 
            {
                auto it = paraules.begin();
                cout << "minimum: " << it -> first << ", " << it -> second << " time(s)";
                
            }
            cout << endl;
        }
        else if (ins == "maximum?") 
        {
            if(paraules.empty()) cout << "indefinite maximum";
            else 
            {
                auto it = --paraules.end();
                cout << "maximum: " << it -> first << ", " << it -> second << " time(s)";
                
            }
            cout << endl;
        }
        else if (ins == "store") 
        {
            cin >> paraula;
            ++paraules[paraula];
        }
        else if (ins == "delete") 
        {
            cin >> paraula;
            auto it = paraules.find(paraula);
            if (it != paraules.end()) 
            {
                --paraules[paraula];
                if (paraules[paraula] == 0) paraules.erase(it);
            }
        }
    }   
}