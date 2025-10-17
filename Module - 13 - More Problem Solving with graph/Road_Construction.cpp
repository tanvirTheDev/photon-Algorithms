#include <iostream>
#include <vector>
#include <cstring> 
using namespace std;

int par[1005];
int group_size[1005];
int maxCom, mx; 
int find(int node){
    if(par[node] == -1) return node;
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2){
    int leader1 = find(node1);
    int leader2 = find(node2); 
    if(leader1 == leader2) return; 
    
    if(group_size[leader1] > group_size[leader2]){
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
        mx = max(mx, group_size[leader1]);
    }
    else{
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
        mx = max(mx, group_size[leader2]);
    }
   
    maxCom--;
}

int main()
{
    int n, m;
    cin >> n >> m;
    maxCom = n;
    memset(par, -1, sizeof(par));
    for(int i = 0; i < 1005; i++) group_size[i] = 1;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
        cout << maxCom << " " << mx << endl;
    }
    
    // cout << maxCom << endl;
    // cout << group_size[2];

    // for (int i = 0; i < 2; i++){
    //     cout << i << " " << par[i] << " " << group_size[i] <<  endl;
    // }
    
    return 0;
}
