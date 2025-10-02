#include <iostream>
#include <vector> 
using namespace std;

int n, m;
vector<string> grid;
vector<vector<bool>> vis;


int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.' && !vis[x][y]);
}

void dfs(int x, int y) {
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny)) {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    vis.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int apartments = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !vis[i][j]) {
                dfs(i, j);
                apartments++;
            }
        }
    }

    cout << apartments << endl;
    return 0;
}
