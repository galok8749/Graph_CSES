#include <bits/stdc++.h>
using namespace std;
int parent[100001];

int find(int x) {
    if(parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

int main() {
    int n, m, x, y, w;
    cin >> n >> m;  

    for(int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    // weight , x, y
    vector<pair<int,pair<int,int>>> g;

    for(int i = 1; i <= m; i++) {
        cin >> x >> y >> w;
        g.push_back(make_pair(w,make_pair(x,y)));
    }

    sort(g.begin(), g.end());

    long long cost = 0;

    for(int i = 0; i < m; i++) {
        w = g[i].first;
        x = g[i].second.first;
        y = g[i].second.second;

        int p1 = find(x);
        int p2 = find(y);

        if(p1 != p2) {
            cost +=w;
            parent[p2] = p1;
        }
    }

    int component = 0;
    for(int i = 1; i <= n; i++) {
        if(parent[i] == i)
            ++component;
    }
    (component == 1) ? cout << cost : cout << "IMPOSSIBLE";
    cout << endl;
}