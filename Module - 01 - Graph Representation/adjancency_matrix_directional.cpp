#include <iostream>
using namespace std;

int main()
{
    

    int n, m;
    cin >> n >> m;
    int adj[n][n];
    memset(adj, 0, sizeof(adj));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i == j) adj[i][j] = 1;
        }
        
    }
    

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;

    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}