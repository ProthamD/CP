#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());
    long long mn = a[0];
    int cnt = 0;
    while (cnt < n && a[cnt] == mn) ++cnt;

    if (cnt == n) {
        cout << -1 << '\n';
        return;
    }

    // b: all elements equal to minimum
    // c: the rest
    cout << cnt << " " << (n - cnt) << '\n';
    for (int i = 0; i < cnt; ++i) {
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
    for (int i = cnt; i < n; ++i) {
        if (i > cnt) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
