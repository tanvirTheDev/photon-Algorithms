#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj_list[105];
bool vis[105];
bool pathVis[105];
bool cycle = false;

void dfs(int src){
    vis[src] = true;
    pathVis[src] = true;
    for (auto child : adj_list[src])
    {
        if(vis[child]  && pathVis[child]) cycle = true;
        if(!vis[child]){
            dfs(child);
          
        }
        
    }
 pathVis[src] = false;
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
    memset(pathVis, false, sizeof(pathVis));
   for (int i = 0; i < n; i++)
   {
    if(!vis[i]){
        dfs(i);
    }
   }


   if(cycle) cout << "Cycle Detected";
   else cout << "No Detected";

   
    
    
    return 0;
}