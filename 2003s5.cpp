#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool cmp(Edge e1, Edge e2) {
    return e1.weight > e2.weight;
}

struct DisjSet {
    vector<int> label;

    DisjSet(int n) {
        label.resize(n);
        for (int i = 0; i < n; i++) {
            label[i] = -1;
        }
    }

    int find(int x) {
        if (label[x] < 0) return x;
        return label[x] = find(label[x]);
    }

    void Union(int x, int y) {
        int a = find(x);
        int b = find(y);

        if (a != b) {
            if (label[a] > label[b]) {
                swap(a, b);
            }
            label[a] += label[b];
            label[b] = a;
        }
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<Edge> edges;
    int c, r, d;
    cin >> c >> r >> d;
    DisjSet ds(c+1);

    for (int i = 0; i < r; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
    }

    sort(edges.begin(), edges.end(), cmp);
    vector<int> ans(c+1, 0);
    ans[1] = -1;
    for (Edge curr: edges) {
        if (ds.find(curr.u) != ds.find(curr.v)) {
            if (ans[curr.u] == 0 || curr.v == 1) ans[curr.u] = curr.weight;
            if (ans[curr.v] == 0 || curr.u == 1) ans[curr.v] = curr.weight;
            //cout << "u: " << ans[curr.u] << " v: " << ans[curr.v] << endl;
            ds.Union(curr.u, curr.v);
            // should backwards update if 1-x appears later on (or statements)
        }
    }

    int res=100001;
    for (int i = 0; i < d; i++) {
        int dc;
        cin >> dc;
        res = min(res, ans[dc]);
    }
    
    cout << res << endl;

    return 0;
}