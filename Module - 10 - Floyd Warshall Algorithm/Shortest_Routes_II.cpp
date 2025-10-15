#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{

    int n, e, q;
    cin >> n >> e >> q;
    int adj_edges[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           if (i == j)
                adj_edges[i][j] = 0;
            else
                adj_edges[i][j] = INT_MAX;

        }
        
    }



    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_edges[a][b] = c;
        adj_edges[b][a] = c;
    }

    // main code

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(adj_edges[i][k] != INT_MAX && adj_edges[k][j] != INT_MAX && adj_edges[i][k] + adj_edges[k][j]  < adj_edges[i] [j]){
                    adj_edges[i][j] = adj_edges[i][k] + adj_edges[k][j];
                }
            }
            
        }
        
    }

    while (q--)
    {
        int q1, q2;
        cin >> q1 >> q2;
        // cout << q1 << q2;
        if(adj_edges[q1][q2] == INT_MAX) cout << "-1" << endl;
        else cout << adj_edges[q1][q2] << endl;
        
        
           
        
    }
    
    
    
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if(adj_edges[i][j] == INT_MAX) cout << "INF" << " ";
    //         else cout << adj_edges[i][j] << " ";
        
    //     }
    //     cout << endl;
        
    // }
    
    
    
    return 0;
}