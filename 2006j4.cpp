#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(8);
vector<int> indeg(8);
vector<int> topo;
priority_queue<int, vector<int>, greater<int>> pq;
int x, y, v;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    adj[1].push_back(7); indeg[7]++;
    adj[1].push_back(4); indeg[4]++;
    adj[2].push_back(1); indeg[1]++;
    adj[3].push_back(4); indeg[4]++;
    adj[3].push_back(5); indeg[5]++;

    while (true) {
        cin >> x >> y;
        if ((x == 0) & (y == 0)) {
            break;
        }
        adj[x].push_back(y);
        indeg[y]++;
    }
    

    for (int i = 1; i < 8; i++) {
        if (indeg[i] == 0) {
            pq.push(i);
        }
    }
    
    while (!pq.empty()) {
        v = pq.top(); pq.pop();
        topo.push_back(v);

        for (auto u: adj[v]) {
            if (--indeg[u] == 0) {
                pq.push(u);
            }
        }
    }


    if (topo.size() == 7) for (auto x: topo) cout << x << " ";
    else cout << "Cannot complete these tasks. Going to bed.";
    cout << endl;

    return 0;
}