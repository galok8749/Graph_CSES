#include <bits/stdc++.h>
using namespace std;
 
 
vector<int> g[100001];
vector<int> color(100001);
bool isBiPartite;

void dfs(int x, int c) {

    color[x] = c;
    
    for(int i = 0; i < g[x].size(); i++) {
        int y = g[x][i];
        if(color[y] == -1) {
            dfs(y, 1 - c);
        }
        else {
            if(color[y] == c) {
                isBiPartite = false;
                return;
            }
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    
    isBiPartite = true;
    for(int i = 0; i <= n; i++) {
        g[i].clear();
        color[i] = -1;
    }
 
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
 
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for(int i = 1; i <= n; i++) {
        if(color[i] == -1) {
            dfs(i, 0);
            if(isBiPartite == false) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << color[i]+1 << " ";
    }
    
    cout << endl;
    return 0;
}