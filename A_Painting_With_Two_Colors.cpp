#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        ll n, a, b; cin >> n >> a >> b;
        if ((n - b) % 2 != 0) {
            cout << "NO\n";
            continue;
        }
        ll y = (n - b + 2) / 2;
        ll L = y, R = y + b - 1;
        if ((n - a) % 2 == 0) {
            cout << "YES\n";
            continue;
        }
        auto c = [&](ll n, ll a, ll b, ll x, ll L, ll R) {
            ll l1 = x, r1 = x + a - 1;
            ll l2 = n - x - a + 2, r2 = n - x + 1;
            if (l1 > l2) { swap(l1,l2); swap(r1,r2); }
            if (r1 < l2) {
                if (l1 >= L && r1 <= R && l2 >= L && r2 <= R) return true;
                return false;
            } else {
                bool ok = true;
                if (l1 <= l2 - 1) {
                    if (!(l1 >= L && l2 - 1 <= R)) ok = false;
                }
                if (r1 + 1 <= r2) {
                    if (!(r1 + 1 >= L && r2 <= R)) ok = false;
                }
                return ok;
            }
        };
        set<ll> s;
        s.insert(1);
        s.insert(max<ll>(1, n - a + 1));
        vector<ll> v = {L, L-(a-1), R, R-(a-1), n-L+1, n-R+1, n-a-L+2, n-a-R+2, (n - a + 2) / 2, (n - a + 3) / 2};
        for (auto z: v) for (int d=-2; d<=2; ++d) s.insert(z+d);
        bool f = false;
        ll xmin= 1, xmax = n - a + 1;
        for (auto x: s) {
            if (x < xmin || x > xmax) continue;
            if (c(n,a,b,x,L,R)) {
                f = true; break;
            }
        }
        cout << (f ? "YES\n" : "NO\n");
    }
    return 0;
}
