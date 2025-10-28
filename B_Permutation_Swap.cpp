#include <iostream>
#include <vector>
#include <algorithm>  // for __gcd
#include <limits.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int g = 0;
    for (int i = 0; i < n; i++) {
        g = __gcd(g, abs(a[i] - (i + 1)));  // <-- works everywhere
    }

    cout << g << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
