#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Edge {
public:
    int a, b;
    long long c;
    Edge(int a, int b, long long c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

const long long INF = 1e18;
long long dis[1005];

int main() {
    int n, e;
    cin >> n >> e;

    vector<Edge> edges;

    for (int i = 0; i < e; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--; 
        b--;
        edges.push_back(Edge(a, b, c));
    }

    int src;
    cin >> src;
    src--; 
    for (int i = 0; i < n; i++) dis[i] = INF;
    dis[src] = 0;

    
    for (int i = 0; i < n - 1; i++) {
        for (auto ed : edges) {
            if (dis[ed.a] != INF && dis[ed.a] + ed.c < dis[ed.b]) {
                dis[ed.b] = dis[ed.a] + ed.c;
            }
        }
    }

   
    bool negCycle = false;
    for (auto ed : edges) {
        if (dis[ed.a] != INF && dis[ed.a] + ed.c < dis[ed.b]) {
            negCycle = true;
            break;
        }
    }

    if (negCycle) {
        cout << "Negative Cycle Detected" << endl;
    } else {
        int query;
        cin >> query;
        while (query--) {
            int dest;
            cin >> dest;
            dest--;
            if (dis[dest] == INF) cout << "Not Possible" << endl;
            else cout << dis[dest] << endl;
        }
    }

    return 0;
}
