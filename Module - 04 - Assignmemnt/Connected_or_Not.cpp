#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


vector<int> adj[1005]; 

bool hasDirectEdgeBFS(int a, int b) {
    if (a == b) return true;  

    queue<int> q;
    vector<bool> visited(1005, false);

    q.push(a);
    visited[a] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

      
        for (int neighbor : adj[node]) {
            if (neighbor == b) return true; 
        }

     
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);  
    }

    int q;
    cin >> q;

    while (q--) {
        int a, b;
        cin >> a >> b;

        if (hasDirectEdgeBFS(a, b)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

