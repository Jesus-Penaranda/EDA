#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void dfs_llegir_componentes(vector<vector<int>>& g, int& actual,vector<bool>& vis, int v, int& min, int& max, int padre) // Implementarem un dfs de forma iterativa
{
    stack<int> s;
    s.push(v);

    while (not s.empty()) 
    {
        int ver = s.top();
        s.pop();
            if(not vis[ver]) 
            {
                vis[ver] = true;
                ++actual;
                for (int i = 0; i < g[ver].size(); ++i) 
                {
                    if (g[ver][i] != padre) // Com no es un graf dirigit(la matriu d'adjacència es simètrica) ignorem al pare vértex
                    {
                        s.push(g[ver][i]);
                        padre = ver;
                    }
                }
                if (actual > max) max = actual; // Si tenim una component connexa més gran que la max, 
                                                // implica que hem descobert una cc més gran

            }
    }
    
}

void trobar_cc(vector<vector<int>>& g, int v) 
{
    vector<bool> vis(g.size(), false);
    
    int max = 0;
    int min = 10000;

    for (int i = 0; i < g.size(); ++i) // Bucle per saber els vértexs que no han sigut visitat, 
                                      //  això implica que formen una component connexa diferente als ja visitats
    {
        int actual = 0;
        if(not vis[i]) 
        {
            dfs_llegir_componentes(g, actual, vis, i, min, max, i);
            if (actual <= min) min = actual;   // Això ho farem per saber-ne el tamany màxim(número de vertexs del component connex) del cc més petit
        }
    }
    cout << min << ' ' << max << endl;
    }



void llegir_graf(int v, int a) 
{
    vector<vector<int>> g(v);
    for (int i = 0; i < a; ++i) 
    {
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    trobar_cc(g, 0);
}

int main() 
{
    int v, a;
    while(cin >> v >> a) 
    {
        llegir_graf(v,a);
    }
}