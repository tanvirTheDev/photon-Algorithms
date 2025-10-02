#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> adj[1000];
bool vis[1000];
void dfs(int src){
    // base 
    vis[src] = true;

    for (auto child : adj[src])
    {
        if(!vis[child]){
            dfs(child);
        }
    }
    
}
 
int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }
    memset(vis, false, sizeof(vis));
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if(vis[i] == false){
            dfs(i);
            cnt++;
            
        }
    }
    cout << cnt << endl;

    
    
    return 0;
}