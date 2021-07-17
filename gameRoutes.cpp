#include <bits/stdc++.h>
using namespace std;

vector<int> g[100001];
long long dp[100001];

#define MOD 1000000007

int dfs(int x, int n) {
    
    if(x == n)
        return 1;
    
    if(dp[x] != -1)
        return dp[x];

    int ans = 0;

    for(int i = 0; i < g[x].size(); i++) {
        
        int y = g[x][i];
                
        ans +=dfs(y, n);
        ans %= MOD;
    }

    return dp[x] = ans;
}

int main() {
    int n, m, x, y;
    cin >> n >> m;

    for(int i = 0; i <= n; i++) {
        g[i].clear();
        dp[i] = -1;
    }

    for(int i = 1; i <= m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
    }

    cout << dfs(1, n) << endl;
}