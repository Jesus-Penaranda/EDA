#include <iostream>
#include <vector>
#include<list>
#include<queue>
using namespace std;

list<int> Topological_sort(int n, int m)
{
    vector<vector<int>> g(n);
    vector<int> v_0(n, 0);
    priority_queue<int, vector<int>, greater<int>> vertice_grau_0;
    list<int> orden;
    for (int i = 0; i < m; ++i)  
    {
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        ++v_0[y];
    }
    for (int i = 0; i < v_0.size(); ++i) 
    {
        if(v_0[i] == 0) vertice_grau_0.push(i);
    }
    
    while(not vertice_grau_0.empty()) 
    {
        int v = vertice_grau_0.top();
        orden.push_back(v);
        vertice_grau_0.pop();
        for (int i = 0; i < g[v].size(); ++i) 
        {
            if(--v_0[g[v][i]] == 0) vertice_grau_0.push(g[v][i]);
        }

    }
    return orden;
}

int main() 
{
    int n,m;
    while (cin >> n >> m) 
    {
        list <int> vertices = Topological_sort(n,m);
        bool start = true;
        for (auto it = vertices.begin(); it != vertices.end(); ++it) 
        {
            if (start) 
            {
                cout << *it;
                start = false;
            }
            else 
                cout << ' ' << *it;
        }
        cout << endl;
       
    }
}
