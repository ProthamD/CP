#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    vector<long long> ans;
    long long power = 10;

    while (1 + power <= n) {
        long long denom = 1 + power;
        if (n % denom == 0) {
            long long x = n / denom;
            ans.push_back(x);
        }
        power *= 10;
    }

    if (ans.empty()) {
        cout << 0 << "\n";
    } else {
        sort(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (auto &x : ans)
            cout << x << " ";
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
