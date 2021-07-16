#include <bits/stdc++.h>
using namespace std;
 
 
vector<int> g[100001];
vector<int> visited(100001);
vector<int> dist(100001,0);
vector<int> parent(100001, 1);
 
int main() {
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i <= n; i++) {
        g[i].clear();
        visited[i] = 0;
        dist[i] = -1;
    }
 
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
 
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    // bfs
    
    queue<int> qu;
    dist[1] = 0;
    qu.push(1);
    visited[1] = 1;
 
    while(!qu.empty()) {
        int x = qu.front();
        qu.pop();
        for(int i = 0; i < g[x].size(); i++) {
            int y = g[x][i];
            if(visited[y] == 1) continue;
 
            dist[y] = dist[x]+1;
            qu.push(y);
            visited[y] = 1;
            parent[y] = x;
        }
    }
    if(dist[n] == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    int node = dist[n]+1;
    vector<int> route(node);
    route[node-1] = n;
 
    for(int i = node-2; i >= 0; i--) {
        route[i] = parent[route[i+1]];
    }
 
    cout << node << endl;
    for(int i = 0; i < node; i++) {
        cout << route[i] << " ";
    }
    cout << endl;
    return 0;
}