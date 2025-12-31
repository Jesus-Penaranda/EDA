#include <iostream>
#include <vector>
using namespace std;




void dfs(int x, int y, const vector<vector<char>>& mapa, vector<vector<bool>>& visited, int n, int m, int& tresor) 
{
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    if (x < 0 or x >= n or y < 0 or y >= m or mapa[x][y] == 'X' or visited[x][y]) return;
    
    visited[x][y] = true;
    if (mapa[x][y] == 't') ++tresor;
    
    for (int i = 0; i < 4; ++i) 
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        dfs(new_x, new_y, mapa, visited, n, m, tresor); 
    }
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
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int tresor = 0;
    dfs(r, c, mapa, visited, n, m, tresor);
    cout << tresor << endl;

}
