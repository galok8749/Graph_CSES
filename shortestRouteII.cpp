#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<vector<long long>> dist(n, vector<long long>(n,LLONG_MAX));

    for(int i = 1; i <= m; i++) {
        int x, y;
        long long w;
        cin >> x >> y >> w;
        dist[x-1][y-1] = min(dist[x-1][y-1], w);
        dist[y-1][x-1] = min(dist[y-1][x-1], w);
    }
    
    for(int i = 0; i < n; i++)
        dist[i][i] = 0;

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][k] != LLONG_MAX and dist[k][j] != LLONG_MAX and dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    while(q--) {
        int x, y;
        cin >> x >> y;
        (dist[x-1][y-1] == LLONG_MAX)? cout << "-1" : cout << dist[x-1][y-1];
        cout << endl;
    }
    return 0;
}