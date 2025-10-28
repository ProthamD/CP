#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    // prefix sum of odd counts
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + (a[i] % 2);
    }

    for (int i = 0; i < q; i++) {
        long long l, r, k;
        cin >> l >> r >> k;

        long long total_odds = prefix[n];  // total odd numbers in array
        long long odds_in_range = prefix[r] - prefix[l - 1];
        long long len = r - l + 1;

        // remove odds in range and add odds from replacing [l, r] with k
        if (k % 2 == 0) {
            total_odds = total_odds - odds_in_range;  // replaced with even numbers
        } else {
            total_odds = total_odds - odds_in_range + len;  // all become odd
        }

        if (total_odds % 2 == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
