#include <bits/stdc++.h>
using namespace std;

int dp[1501][1501];
int g[1501][1501];
int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int n, res;

int dfs(int r, int c) {
    if (dp[r][c] != -1) return dp[r][c];
    int out = 0;

    for (int i = 0; i < 4; i++) {
        int nrow = r + directions[i][0];
        int ncol = c + directions[i][1];

        if (g[nrow][ncol] > g[r][c] && nrow >= 0 && nrow < n && ncol >= 0 && ncol < n) {
            out = max(out, dfs(nrow, ncol) + 1);
        }
    }
    
    dp[r][c] = out;
    return out;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res = max(res, dfs(i, j));
        }
    }

    cout << res << endl;
    
    return 0;
}