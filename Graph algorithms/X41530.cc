#include <iostream>
#include <vector>
using namespace std;

void arbol(vector<vector<int>>& g, int i, int pd, vector<bool>& vis, bool& b) 
{
    if (not vis[i]) 
    {
        vis[i] = true;
        for (int j = 0; j < g[i].size(); ++j) 
        {
            if (g[i][j] != pd) 
            {
                arbol(g,g[i][j],i,vis, b);
                if (b) return;
            }
        }
    }
    else b = true;
}

void dfs(vector<vector<int>>& g) 
{
    int n = g.size();
    vector<bool> vis(n, false);
    int tr = 0;
    for (int i = 0; i < n; ++i)
    {
        if (not vis[i]) 
        {
            bool b = false;
            arbol(g,i,i,vis,b);
            if(b)
            {
                cout << "no" << endl;
                return;
            }
            else ++tr;
        }
        
    }
    cout << tr << endl;
}

int main() 
{
    int n,m;
    while(cin >> n >> m) 
    {
        vector<vector<int>> g(n);
        for(int i = 0; i < m; ++i) 
        {
            int x,y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs(g);
    }
}
