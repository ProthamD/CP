#include<iostream>
#include<vector>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    int res = 1;
    for(int i = 0; i < n; ++i) {
        if(a[i] > b[i]){
            res += a[i] - b[i]; 
        }
    }
    cout << res << endl;
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