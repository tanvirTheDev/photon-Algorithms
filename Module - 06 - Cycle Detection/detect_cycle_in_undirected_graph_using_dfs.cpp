#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj_list[105];
bool vis[105];
int parent[105];
bool cycle = false;

void dfs(int src){
    cout << src << " " << endl;
    vis[src] = true;
    for (auto child : adj_list[src])
    {
        if(vis[child] && parent[src] != child) cycle = true;
        if(!vis[child]){
            parent[child] = src;
            dfs(child);
          
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
   memset(parent, -1, sizeof(parent));
   for (int i = 0; i < n; i++)
   {
    if(!vis[i]){
        dfs(i);
    }
   }

   for (int i = 0; i < n; i++)
   {
        cout << i << " parent " << parent[i] << endl;
   }
   

   if(cycle) cout << "Cycle Detected";
   else cout << "No Detected";

   
    
    
    return 0;
}