#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

void solve(){
    //my codes here
    int n;
    cin >> n;
    // if(n <= 0 || n > 1000000){
    //     return;
    // }

    vector<long long> a(n);
    for(int i = 0; i < n-1; i++) {
        cin >> a[i];
    }
    int res  = 0;
    for(int i = 0; i < n-1; i++) {
        if(a[i] < 0) {
            res += abs(a[i]);
        } else {
            res -= a[i];
        }
    }
    cout << res << endl;
    return;
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