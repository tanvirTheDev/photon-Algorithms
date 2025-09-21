#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> adj[1000];
bool vis[1000];
int level[1000];
int parent[1000];
void bfs(int src){
    queue<int> q;

    q.push(src);
    vis[src] = true;
    level[src] = 0;


    while (!q.empty()){

    int node = q.front();
    q.pop();

    // cout << node << " ";


    for (auto &&child : adj[node])
    {
       if(!vis[child]){
        q.push(child);
        vis[child] = true;
        level[child] = level[node] + 1;
        parent[child] = node;
       } 
    }
    }
}
 
int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
       
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));
    int src, des;
    cin >> src >> des;
    bfs(src);
    if(vis[des]) cout << "YES" << endl;
    else cout << "NO";
    cout << level[des] << endl;

    int node = des;
    vector<int> path;
    while (node != -1)
    {
    path.push_back(node);
    node = parent[node];
    }
    
    reverse(path.begin(), path.end());

    for (auto &&x : path)
    {
        cout << x << " ";
    }
    

    // for (int  i = 0; i  < n; i++)
    // {
    //     cout << i << " " << parent[i] << endl;
    // }
    
    
    return 0;
}