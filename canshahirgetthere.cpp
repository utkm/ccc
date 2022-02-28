#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, e, a, b, x, y;
    cin >> n >> e >> a >> b;
    
    vector<vector<int>> adj(n+1);
    queue<int> q;
    bool visited[n+1];
    for (int i = 1; i < n; i++) visited[i]=false;
    visited[a] = true;
    q.push(a);
    
    for (int i = 0; i < e; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (auto x: adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
    
    if (visited[b]) {
        cout << "GO SHAHIR!" << endl;
    } else {
        cout << "NO SHAHIR!" << endl;
    }

    return 0;
}