#include <bits/stdc++.h>
using namespace std;

int directions[8][2] = {{2,1}, {2,-1}, {1, 2}, {1,-2}, {-1,2}, {-1,-2}, {-2,1}, {-2,-1}};
int g[9][9];
int dis[9][9] = {0};
bool vis[9][9] = {0};

queue<pair<int, int>> q;
pair<int, int> start, dest;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> start.first >> start.second;
    cin >> dest.first >> dest.second;

    q.push(start);
    vis[start.first][start.second] = 1;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nr = r + directions[i][0];
            int nc = c + directions[i][1];

            if (nr >= 1 && nr <= 8 && nc >= 1 && nc <= 8 && !vis[nr][nc]) {
                dis[nr][nc] = dis[r][c] + 1;
                vis[nr][nc] = 1;
                q.push({nr, nc});
            }
            if (vis[dest.first][dest.second]) {
                cout << dis[dest.first][dest.second] << endl;
                return 0;
            }
        }
    }
}