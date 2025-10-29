#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<int> freqS(26, 0);
    for (char c : t) {
        freqS[c - 'A']++;
    }
    for (int i = n-1; i >= 0; i--) {
        if(freqS[s[i] - 'A'] > 0) {
            freqS[s[i] - 'A']--;
        } else {
            s[i] = '.';
        }
    }
    string result = "";
    for(int i = 0; i < n; i++) {
        if(s[i] != '.') {
            result += s[i];
        }
    }
    if(result == t) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--)
        solve();

    return 0;
}
