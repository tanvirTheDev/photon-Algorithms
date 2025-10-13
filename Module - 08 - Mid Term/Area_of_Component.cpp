#include <iostream>
#include <vector>
#include <cstring> 
#include <climits> 
using namespace std;

const int MAX = 1005;
char grid[MAX][MAX];
bool vis[MAX][MAX];
int n, m;
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};


int dfs(int i, int j) {
    vis[i][j] = true;
    int area = 1; 
    for (auto dir : d) {
        int ni = i + dir.first;
        int nj = j + dir.second;
        if (ni >= 0 && ni < n && nj >=0 && nj < m 
            && grid[ni][nj] == '.' && !vis[ni][nj]) {
            area += dfs(ni, nj);
        }
    }

    return area;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    int min_area = INT_MAX;
    bool found = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !vis[i][j]) {
                int area = dfs(i, j);
                min_area = min(min_area, area);
                found = true;
            }
        }
    }

    if (!found) cout << -1 << endl;
    else cout << min_area << endl;

    return 0;
}
