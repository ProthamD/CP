#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    long long x;
    cin >> n >> k >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    set<long long> used; 
    for(auto pos: a) used.insert(pos);

    vector<pair<long long,long long>> gaps;
    if(a[0] > 0) gaps.push_back({0, a[0]-1});
    for(int i=0;i<n-1;i++) if(a[i+1]-a[i]>1) gaps.push_back({a[i]+1, a[i+1]-1});
    if(a[n-1]<x) gaps.push_back({a[n-1]+1, x});

    sort(gaps.begin(), gaps.end(), [](pair<long long,long long>& p1, pair<long long,long long>& p2){
        return (p1.second - p1.first) > (p2.second - p2.first);
    });

    vector<long long> teleports;
    for(auto g: gaps) {
        long long l = g.first, r = g.second;
        long long mid = l + (r-l)/2;
        queue<long long> q;
        q.push(mid);
        int offset = 1;
        while(!q.empty() && (int)teleports.size()<k) {
            long long p = q.front(); q.pop();
            if(used.find(p)==used.end()) {
                teleports.push_back(p);
                used.insert(p);
            }
            if(offset<=r-l) {
                if(mid - offset >= l) q.push(mid - offset);
                if(mid + offset <= r) q.push(mid + offset);
            }
            offset++;
        }
        if((int)teleports.size()>=k) break;
    }

    long long pos = 0;
    while((int)teleports.size()<k && pos<=x) {
        if(used.find(pos)==used.end()) {
            teleports.push_back(pos);
            used.insert(pos);
        }
        pos++;
    }

    for(auto t: teleports) cout << t << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}
