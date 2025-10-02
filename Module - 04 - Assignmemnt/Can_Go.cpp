#include <iostream>
#include <vector>
#include <queue>
using namespace std;


char grid[105][105];
bool vis[105][105];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n,m;
int ax, ay, bx, by; 
bool valid(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m){
        return false;
    }
    if(grid[i][j] == '#'){
        return false;
    } 
    else {
        return true;
    }
}

void dfs(int si, int sj){
    vis[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci, cj;
        ci = si +  d[i].first;
        cj = sj + d[i].second;
        if(valid(ci, cj) == true && !vis[ci][cj]){
            dfs(ci, cj);
        }
    }
    
}
 
int main()
{

    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
           cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                ax = i; ay = j;
            }
            if (grid[i][j] == 'B') {
                bx = i; by = j;
            }
        }
        
    }

    dfs(ax, ay);

    if(vis[bx][by]) cout << "YES";
    else cout << "NO";
    
    return 0;
}