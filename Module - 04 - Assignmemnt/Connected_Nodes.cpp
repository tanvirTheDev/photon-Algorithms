#include <iostream>
#include <vector>
#include <queue>


using namespace std;


vector<int> adj[1000];
bool visited[1000];
void bfs(int src){

    queue<int> q;
    

    q.push(src);
    visited[src] = true;

    while (!q.empty()) {
        // ber kore ana
        int node = q.front();
        q.pop();
        
        // oi node e kaj kora
        // cout << "Visiting: " << node << endl;

        // childeren push kora
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                cout << neighbor << " ";
            }
        }
    }
}

int main()
{
    
    int n, m;
    cin >> n >> m;
    

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // memset(visited, false, sizeof(visited));
 
    // 0 থেকে যেসব node directly connected
    

//    bfs(0);


    int q;
    cin >> q;
    while (q--)
    {
        int a;
        cin >> a;
        if (adj[a].empty()) {
            cout << -1 << endl;
        }else{
        vector<int> neighbors = adj[a];
        sort(neighbors.rbegin(), neighbors.rend()); 
        for (int neighbor : neighbors) {
        cout << neighbor << " ";
        }
        cout << endl;
    }
    

    }
    

    return 0;
}