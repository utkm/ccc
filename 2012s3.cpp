#include <bits/stdc++.h>
using namespace std;

int freq[1001];
int n, temp, ans=0;
int mostfrequent=0, sndmostfrequent=0;
int nmostfrequent=0, nsndmostfrequent=0;
int upperf, lowerf;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> temp;
        freq[temp]++;
    }

    for (int i=0; i<1000; i++) {
        mostfrequent = max(mostfrequent, freq[i]);
    }
    
    for (int i=0; i<1000; i++) {
        nmostfrequent += freq[i] == mostfrequent;
    }

    for (int i=0; i<1000; i++) {
        if (freq[i] != mostfrequent) {
            sndmostfrequent = max(sndmostfrequent, freq[i]);
        }
    }

    for (int i=0; i<1000; i++) {
        nsndmostfrequent += freq[i] == sndmostfrequent;
    }


    if (nmostfrequent > 1) {
        for (int i=1000; i>=0; i--) {
            if (freq[i] == mostfrequent) {
                ans = i;
                break;
            }
        }
        for (int i=0; i<=1000; i++) {
            if (freq[i] == mostfrequent) {
                cout << ans - i << endl;
                return 0;
            }
        }
    }

    for (int i=0; i<1000; i++) {
        if (freq[i] == mostfrequent) {
            upperf = i;
            break;
        }
    }

    for (int i=0; i<1000; i++) {
        if (freq[i] == sndmostfrequent) {
            ans = max(ans, abs(upperf - i));
        }
    }

    cout << ans << endl;

    return 0;
}