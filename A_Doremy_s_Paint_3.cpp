#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

void solve(){
    //my codes here
    int n;
    cin >> n;

    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    int res = n / 2;
        if(mp.size() > 2) {
            cout << "No" << endl;
            return;
        }
    for(auto it : mp) {
        if(it.second == res || it.second == n - res || it.second == n) {
            continue;
        } else {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}