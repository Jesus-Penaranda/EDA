#include <iostream>
#include <vector>
using namespace std;

bool dfs_color(const vector<vector<int>>& g, int node, int color, vector<int>& colors) 
{
    colors[node] = color; // Asignar el color al nodo actual

    for (int neighbor : g[node]) 
    {
        if (colors[neighbor] == -1) // Si el vecino no está coloreado
        {
            if (!dfs_color(g, neighbor, 1 - color, colors)) 
                return false; // Si no se puede colorear, no es bipartito
        } 
        else if (colors[neighbor] == colors[node]) 
        {
            return false; // Si un vecino tiene el mismo color, no es bipartito
        }
    }
    return true;
}

bool check_bipartite(const vector<vector<int>>& g) 
{
    int n = g.size();
    vector<int> colors(n, -1); // -1 indica no coloreado

    for (int i = 0; i < n; ++i) 
    {
        if (colors[i] == -1) // Si el nodo no está coloreado, verificamos su componente
        {
            if (!dfs_color(g, i, 0, colors)) 
                return false;
        }
    }
    return true;
}

int main() 
{
    int n, m;
    while (cin >> n >> m) 
    {
        vector<vector<int>> g(n);
        for (int i = 0; i < m; ++i) 
        {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        if (check_bipartite(g)) 
            cout << "yes" << endl;
        else 
            cout << "no" << endl;
    }
}
