#include <bits/stdc++.h>
using namespace std;

int q;
long long k, m, n;
vector<long long> palin;
const int MAXN = 100001;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> q >> k;
    for (int i = 0; i < MAXN; i++) {

        string temp1 = to_string(i); // 14
        string temp2 = temp1;
        reverse(temp2.begin(), temp2.end()); // 41

        long long num1 = atoll((temp1+temp2).c_str()); // 1441
        
        if (num1 > 0 && num1 % 10 != 0 && num1 % k == 0) {
            palin.push_back(num1);
        }
        
        temp2 = temp2.substr(1, temp2.length()-1);
        num1 = atoll((temp1+temp2).c_str());
        if (num1 > 0 && num1 % 10 != 0 && num1 % k == 0) {
            palin.push_back(num1);
        }
    }

    sort(palin.begin(), palin.end());

    for (int i = 0; i < q; i++) {
        cin >> m >> n;
        // num of palins between m and n inclusive
        int idx1 = lower_bound(palin.begin(), palin.end(), m) - palin.begin();
        int idx2 = upper_bound(palin.begin(), palin.end(), n) - palin.begin();
        cout << idx2 - idx1 << endl;
    }

    return 0;
}