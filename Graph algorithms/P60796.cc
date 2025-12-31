#include <iostream>
#include <vector>
#include<queue>
using namespace std;

int INF = 10000000;


int bfs(int x, int y, const vector<vector<char>>& mapa, int n, int m) 
{

    int distancia_min = INF;
    vector<vector<bool>> visited(n, vector<bool>(m, false)); 
    queue<pair<int,int>> ver;
    vector<vector<int>> distancia(n, vector<int>(m,0));
    vector<int> dirx = {-1,1,0,0};
    vector<int> diry = {0,0,-1,1};
    

    visited[x][y] = true;
    ver.push(make_pair(x,y));
    if (mapa[x][y] == 't') return 0;

    while(not ver.empty()) 
    {
        int vx = ver.front().first; int vy = ver.front().second;
        ver.pop();
        
        for(int i = 0; i < 4; ++i) 
        {
            int caminox = vx + dirx[i];
            int caminoy = vy + diry[i];
            if ((caminox >= 0 and caminox < n) and (caminoy >= 0 and caminoy < m) and (not visited[caminox][caminoy])) 
            {
                visited[caminox][caminoy] = true;
                distancia[caminox][caminoy] = distancia[vx][vy] + 1;

                if (mapa[caminox][caminoy] == 't') 
                {
                    if (distancia[caminox][caminoy] < distancia_min) distancia_min = distancia[caminox][caminoy];
                }
                else if (mapa[caminox][caminoy] != 'X') 
                {
                    ver.push(make_pair(caminox, caminoy));          
                }
            }
        }
    }
    return distancia_min; 
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> mapa(n, vector<char>(m));
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) 
            cin >> mapa[i][j];
            
        
    int r, c;   
    cin >> r >> c;
    r--; c--;

    int dis = bfs(r, c, mapa, n, m);

    if (dis == INF) cout << "no treasure can be reached";
    else cout << "minimum distance: " << dis;
    cout << endl;

}
