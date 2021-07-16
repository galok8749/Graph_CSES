#include <bits/stdc++.h>
using namespace std;
 
vector<pair<int,int>> g[100001];
vector<int> visited(100001);
vector<long long> dist(100001);
 
int main() {
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i <= n; i++) {
        g[i].clear();
        visited[i] = 0;
        dist[i] = LLONG_MAX;
    }
 
    for(int i = 1; i <= m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
 
        g[x].push_back({y,w});
    }
    
    // min heap
    // pair of distance and node
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long, int> > > minHeap;
 
    dist[1] = 0;
 
    minHeap.push({0, 1});   
 
    while(!minHeap.empty()) {
        int x = minHeap.top().second;
        minHeap.pop();
        if(visited[x] == 1)
            continue;
        visited[x] = 1;
 
        for(int i = 0; i < g[x].size(); i++) {
            int y = g[x][i].first;
            int w = g[x][i].second;
 
            if(dist[y] > dist[x] + w) {
                dist[y] = dist[x] + w;
                minHeap.push({dist[y], y});
            }
        }
    }
 
    for(int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    } 
    cout << endl;
 
    return 0;
}