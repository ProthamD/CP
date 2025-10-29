#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n), c(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> c[i];

    // Coordinate compression
    vector<long long> vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int m = vals.size();

    vector<long long> dp(m, LLONG_MAX);

    // Initialize dp for first element
    for(int j=0;j<m;j++){
        dp[j] = (a[0]==vals[j]?0:c[0]);
    }

    // DP for positions 2..n
    for(int i=1;i<n;i++){
        vector<long long> new_dp(m, LLONG_MAX);
        long long pref_min = LLONG_MAX;
        for(int j=0;j<m;j++){
            pref_min = min(pref_min, dp[j]);
            new_dp[j] = pref_min + (a[i]==vals[j]?0:c[i]);
        }
        dp = new_dp;
    }

    long long ans = *min_element(dp.begin(), dp.end());
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}
