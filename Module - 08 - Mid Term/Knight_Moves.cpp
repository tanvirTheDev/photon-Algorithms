#include <bits/stdc++.h>
using namespace std;

int n, m;
bool vis[105][105];
int level[105][105];

vector<pair<int, int>> moves = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

int bfs(int si, int sj, int di, int dj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty()) {
        auto par = q.front();
        q.pop();
        int x = par.first;
        int y = par.second;

        if (x == di && y == dj) {
            return level[x][y]; 
        }

        for (auto move : moves) {
            int nx = x + move.first;
            int ny = y + move.second;

            if (valid(nx, ny) && !vis[nx][ny]) {
                vis[nx][ny] = true;
                level[nx][ny] = level[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return -1; 
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int si, sj, di, dj;
        cin >> si >> sj; 
        cin >> di >> dj; 

        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));

        cout << bfs(si, sj, di, dj) << endl;
    }
    return 0;
}
