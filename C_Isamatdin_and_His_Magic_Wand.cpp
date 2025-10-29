#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    bool mixed = false;
    int parity = arr[0] % 2;
    for (int i = 1; i < n; i++) {
        if (arr[i] % 2 != parity) {
            mixed = true;
            break;
        }
    }

    if (mixed) sort(arr.begin(), arr.end());

    for (int x : arr) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
