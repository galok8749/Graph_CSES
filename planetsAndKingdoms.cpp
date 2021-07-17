#include <bits/stdc++.h>
using namespace std;

vector<int> g[100001];
vector<int> rg[100001];
int visited[100001];
int stronglyConnectedComponent = 0;
vector<int> kingdom(100001, -1);

void dfs1(int x, stack<int> &s) {
    visited[x] = 1;

    for(int i = 0; i < g[x].size(); i++) {
        int y = g[x][i];
        if(visited[y] == 0)
            dfs1(y, s);
    }
    s.push(x);
}

void dfs2(int x) {
    // cout << x << " ";
    visited[x] = 1;
    kingdom[x] = stronglyConnectedComponent;

    for(int i = 0; i < rg[x].size(); i++) {
        int y = rg[x][i];
        if(visited[y] == 0)
            dfs2(y);
    }
}

int main() {
    int n, m, x, y;
    cin >> n >> m;  

    for(int i = 1; i <= m; i++) {
        cin >> x >> y;

        g[x].push_back(y);
        rg[y].push_back(x);
    }

    memset(visited, 0, sizeof(visited));

    stack<int> s;
    
    for(int i = 1; i <= n; i++) {
        if(visited[i] == 0)
            dfs1(i, s);
    }
    
    memset(visited, 0, sizeof(visited));

    while(!s.empty()) {
        int x = s.top();
        s.pop();
        if(visited[x] == 0) {
            // cout << x << "----\n";
            ++stronglyConnectedComponent;
            dfs2(x);
            // cout << endl;
        }
    }
    cout << stronglyConnectedComponent << endl;
    for(int i = 1; i <= n; i++) {
        cout << kingdom[i] << " ";
    }
    cout << endl;
    return 0;
}