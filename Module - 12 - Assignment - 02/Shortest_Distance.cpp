#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<long long>> adj_edges(n, vector<long long>(n, LLONG_MAX));

    for(int i = 0; i < n; i++) adj_edges[i][i] = 0;

    while(e--) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--; b--; 
        adj_edges[a][b] = min(adj_edges[a][b], c); 
    }

    
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(adj_edges[i][k] != LLONG_MAX && adj_edges[k][j] != LLONG_MAX) {
                    adj_edges[i][j] = min(adj_edges[i][j], adj_edges[i][k] + adj_edges[k][j]);
                }
            }
        }
    }

    int q;
    cin >> q;
    while(q--) {
        int q1, q2;
        cin >> q1 >> q2;
        q1--; q2--; 
        if(adj_edges[q1][q2] == LLONG_MAX) cout << "-1\n";
        else cout << adj_edges[q1][q2] << "\n";
    }

    return 0;
}
