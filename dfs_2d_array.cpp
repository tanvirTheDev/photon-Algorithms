#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> adj[1000];
bool vis[1000];

void bfs(int src){
    queue<int> q;

    q.push(src);
    vis[src] = true;

    while (!q.empty()){

    int node = q.front();
    q.pop();

    // cout << node << " ";


    for (auto &&child : adj[node])
    {
       if(!vis[child]){
        q.push(child);
        vis[child] = true;
       } 
    }
    }
    {
        /* code */
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
    
    
        

    
    
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << ":" ;
    //     for (auto child : adj[i])
    //     {
    //         cout << child << " ";
    //     }
    //     cout << endl;
        
    // }


    memset(vis, false, sizeof(vis));
    int src, des;
    cin >> src >> des;
    bfs(src);
    if(vis[des]) cout << "YES";
    else cout << "NO";
    
    return 0;
}