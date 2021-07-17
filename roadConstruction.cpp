#include <bits/stdc++.h>
using namespace std;

int parent[100001];
int sizze[100001];

int find(int x) {
    if(parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

int main() {
    int n, m, x, y;
    cin >> n >> m;  

    for(int i = 0; i <= n; i++) {
        parent[i] = i;
        sizze[i] = 1;
    }

    int component = n;
    int maxSizeComponent = 1;

    for(int i = 1; i <= m; i++) {
        cin >> x >> y;

        int p1 = find(x);
        int p2 = find(y);

        if(p1 != p2) {
            component--;
            parent[p2] = p1;
            sizze[p1] +=sizze[p2];

            maxSizeComponent = max(maxSizeComponent, sizze[p1]);
        }
        cout << component << " " << maxSizeComponent << endl;
    }
    return 0;
}