#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

void solve(){
    //my codes here
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int m = t.size();
    if(n != m) {
        cout << "NO" << endl;
        return;
    }
    vector<int> freq(26, 0);
    for(auto it: s) {
        freq[it - 'a']++;
    }   
    for(auto it: t) {
        freq[it - 'a']--;
    }
    for(int i = 0; i < 26; i++) {
        if(freq[i] != 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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