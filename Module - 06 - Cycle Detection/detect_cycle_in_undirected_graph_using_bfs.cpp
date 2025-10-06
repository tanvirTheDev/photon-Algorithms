#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj_list[105];
bool vis[105];
int parent[105];
bool cycle = false;
void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty()){
        int par = q.front();
        cout << par << endl;
        q.pop();

    for (auto child : adj_list[par])
    {
        if(vis[child] && parent[par] != child) cycle = true;
        if(!vis[child]){
            q.push(child);
            vis[child] = true;
            parent[child] = par;
        }
    }
    
        
    }
    
}

int main()
{
    int n, m;
    cin >> n >> m;

    while (m--){
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
   memset(vis, false, sizeof(vis));
   memset(parent, false, sizeof(parent));
   for (int i = 0; i < n; i++)
   {
    if(!vis[i]){
        bfs(i);
    }
   }

   if(cycle) cout << "Cycle Detected";
   else cout << "No Detected";

   
    
    
    return 0;
}