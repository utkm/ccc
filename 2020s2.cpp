#include <bits/stdc++.h>
using namespace std;

int m, n, temp;
vector<vector<pair<int, int>>> g(1001*1001);
bool visited[1001][1001];

bool solve(pair<int, int> node) {
    queue<pair<int, int>> q;
    q.push(node); 
    visited[node.first][node.second] = 1;

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        int r = cur.first;
        int c = cur.second;

        for (pair<int, int> neighbour: g[r*c]) {
            if (neighbour.first == 1 && neighbour.second == 1) {
                return 1;
            }
            if (!visited[neighbour.first][neighbour.second]) {
                visited[neighbour.first][neighbour.second] = 1;
                q.push(neighbour);
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> temp;
            g[temp].push_back({i+1, j+1});
        }
    }

    puts(solve({m, n}) ? "yes" : "no");

    return 0;
}