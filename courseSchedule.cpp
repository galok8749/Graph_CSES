#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x, y;
    cin >> n >> m;

    vector<int> g[n+1];
    vector<int> inDegree(n+1, 0);

    for(int i = 1; i <= m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        inDegree[y] +=1;
    }

    queue<int> qu;
    for(int i = 1; i <= n; i++) {
        if(inDegree[i] == 0)
            qu.push(i);
    }

    vector<int> ans;

    while(!qu.empty()) {
        x = qu.front();
        qu.pop();

        ans.push_back(x);
        
        for(int i = 0; i < g[x].size(); i++) {
            int y = g[x][i];
            if(--inDegree[y] == 0)
                qu.push(y);
        }
    }

    if(ans.size() == n) {
        for(int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl; 
    }
    else {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}