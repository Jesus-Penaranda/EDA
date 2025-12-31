#include <iostream>
#include <vector>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


bool dfs(int x, int y, const vector<vector<char>>& mapa, vector<vector<bool>>& visited, int n, int m) 
{

    if (x < 0 || x >= n || y < 0 || y >= m || mapa[x][y] == 'X' || visited[x][y]) {
        return false;
    }

    visited[x][y] = true;
    if (mapa[x][y] == 't') return true;
    
    for (int i = 0; i < 4; ++i) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];


        if (dfs(new_x, new_y, mapa, visited, n, m)) return true;
        
    }
    return false; 
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> mapa(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mapa[i][j];
        }
    }

    int r, c;
    cin >> r >> c;
    r--; c--;
    vector<vector<bool>> visited(n, vector<bool>(m, false));


    if (dfs(r, c, mapa, visited, n, m)) cout << "yes" << endl;
    else cout << "no" << endl;
}
