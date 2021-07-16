#include <bits/stdc++.h>
using namespace std;
int parent[100001];
 
void init() {
    for(int i = 0; i <= 100000; i++)
        parent[i] = i;
}
 
int find(int x) {
    if(parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}
 
int main() {
    init();
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
 
        int p1 = find(x);
        int p2 = find(y);
 
        if(p1 != p2)
            parent[p2] = p1;
    }
 
    vector<int> nodes;
    
 
    for(int i = 1; i <= n; i++) {
        if(parent[i] == i) {
            // cout << i << endl;
            nodes.push_back(i);
        }
    }
 
    int roads = nodes.size();
    roads--;
 
     
    cout << roads << endl;
    for(int i = 0; i < roads; i++) {
        cout << nodes[i] << " " << nodes[i+1] << endl;
    }
 
    return 0;
}