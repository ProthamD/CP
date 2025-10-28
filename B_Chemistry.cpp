#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;


void solve(){
    int n, k;
    cin >> n >> k;
    string s1;
    cin >> s1;
    vector<int> a(26, 0);

    for(int i = 0; i < n; i++) {
        a[s1[i] - 'a']++;
    }
    int oddfcnt = 0;
    for(int i = 0; i < 26; i++) {
        oddfcnt += a[i] % 2;
    }
    if(oddfcnt <= k+1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

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