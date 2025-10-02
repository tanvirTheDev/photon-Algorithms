#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

int n, m;
vector<string> grid;
vector<vector<bool>> vis;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.' && !vis[x][y]);
}

int dfs(int x, int y) {
    vis[x][y] = true;
    int size = 1;  
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny)) {
            size += dfs(nx, ny);
        }
    }
    return size;
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    vis.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<int> apartments;

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !vis[i][j]) {
                int size = dfs(i, j);
                apartments.push_back(size);
            }
        }
    }

    sort(apartments.begin(), apartments.end());

    for (int i = 0; i < apartments.size(); i++) {
        if (i > 0) cout << " ";
        cout << apartments[i];
    }
    cout << endl;

    return 0;
}
