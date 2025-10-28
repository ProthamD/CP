#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    if(a[n-1] != b[n-1]) {
        cout << "NO" << endl;
        return;
    }

    vector<int> d(n-1);
    for(int i = 0; i < n-1; i++) {
        d[i] = a[i] ^ b[i];
    }
    bool ok = true;
    for(int i = 0; i < n-1 && ok; ) {
        if(d[i] == 0) {
            ++i;
            continue;
        }
        int j = i;
        bool found = false;
        for (; j < n-1; ++j) {
            if (d[j] == a[j+1]) {
                i = j+1;
                found = true;
                break;
            }
            if (j == n-2 || d[j+1] != (d[j] ^ a[j+1])) {
                ok = false;
                break;
            }
        }
        if (!found && j >= n-1) {
            ok = false;
        }
    }
    if(ok == true){
        cout << "YES" << endl;
    }
    else{
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