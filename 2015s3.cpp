#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    set<int, greater<int>> gates;

    int num_gates, p, d;
    cin >> num_gates >> p;

    for (int i = 1; i <= num_gates; i++) {
        gates.insert(i);
    }
    
    int ans = 0;
    bool status = true;
    for (int i = 0; i < p; i++) {
        cin >> d;

        if (!status) {
            continue;
        }

        if (gates.lower_bound(d) != gates.end()) {
            ans++;
            gates.erase(gates.lower_bound(d));
        } else {
            status = false;
        }
    }

    cout << ans << endl;

    return 0;
}