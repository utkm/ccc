#include <bits/stdc++.h>
using namespace std;

// up down left right
int directions[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
char g[26][26];
bool vis[26][26];
int flooring, maxr, maxc;
vector<int> areas;
char val;
int area = 0;

int bfs(pair<int, int> point) {
    area = 1;
    int rcurr = point.first; int ccurr = point.second;
    if (vis[rcurr][ccurr]) {
        return 0;
    }
    vis[rcurr][ccurr] = 1;
    queue<pair<int, int>> q;
    q.push({rcurr, ccurr});
    //cout << rcurr << " " << ccurr << endl;
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + directions[i][0];
            int nc = c + directions[i][1];

            if (nr >= 0 && nr < maxr && nc >= 0 && nc < maxc) {
                if (g[nr][nc] == '.' && !vis[nr][nc]) {
                    //cout << nr << " " << nc << endl; 

                    vis[nr][nc] = 1;
                    area++;
                    q.push({nr, nc});
                }
            }
        }
    }
    areas.push_back(area);
    return 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> flooring >> maxr >> maxc;

    for (int r = 0; r < maxr; r++) {
        for (int c = 0; c < maxc; c++) {
            cin >> g[r][c];
        }
    }

    // 0 room, 1 walls
    for (int i = 0; i < maxr; i++) {
        for (int j = 0; j < maxc; j++) {
            if (g[i][j] == '.' && !vis[i][j]) {
                bfs({i, j});
            }
        }
    }
    
    sort(areas.begin(), areas.end(), greater<int>());
    int rcnt=0;
    for (auto x: areas) {
        if (flooring - x >= 0) {
            flooring -= x;
            rcnt++;
        } else {
            break;
        }
    }

    cout << rcnt << " room";
    rcnt == 1 ? cout << ", " : cout << "s, ";
    cout << flooring << " square metre(s) left over" << endl;

    return 0;
}