#include<iostream>
#include<queue>

using namespace std;

int main() 
{
    priority_queue<int> nums;

    char ins;

    while (cin >> ins) 
    {
        int x;
        if (ins == 'A') 
        {
            if (not nums.empty()) cout << nums.top() << endl;
            else cout << "error!" << endl;
        }
        else if (ins == 'S') 
        {
            cin >> x;
            nums.push(x);
        }
        else if (ins == 'R') 
        {
            if(not nums.empty()) nums.pop();
            else cout << "error!" << endl;
        }
        else if (ins == 'I') 
        {
            cin >> x;
            if (not nums.empty()) 
            {
                int aux = nums.top();
                nums.pop();
                aux += x;
                nums.push(aux);
            }
            else cout << "error!" << endl;
        }
        else if (ins == 'D') 
        {
            cin >> x;
            if (not nums.empty())
            {
                int aux = nums.top();
                nums.pop();
                aux -= x;
                nums.push(aux);
            }
            else cout << "error!" << endl;
        }

    }
}