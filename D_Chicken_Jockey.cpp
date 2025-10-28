#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll calculate_bonus(const vector<ll>& h, int n) {
    ll a = 0, b = 0;
    for (int i = 1; i < n; ++i) {
        ll w = min((ll)i, h[i]) - 2;
        if (w < 0) w = 0;
        ll c = max(b, a + w);
        a = b;
        b = c;
    }
    return b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; 
        cin >> n;
        vector<ll> health(n);
        for (int i = 0; i < n; ++i) cin >> health[i];

        ll base = 0;
        for (ll x : health) base += x;
        base -= (n - 1);

        ll bonus = calculate_bonus(health, n);

        cout << base - bonus << "\n";
    }
    return 0;
}
