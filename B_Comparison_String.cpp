#include <bits/stdc++.h>
#include <string>
#include <climits>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s; // only one string!
    if(n == 1) {
        cout << 2 << endl;
        return;
    }

    int maxi = 0;
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            cnt++;
            maxi = max(maxi, cnt);
        } else {
            cnt = 0;
        }
    }
    maxi = maxi + 2;
    cout << maxi << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
}
