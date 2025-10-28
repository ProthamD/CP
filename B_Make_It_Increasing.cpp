#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

void solve(){
    //my codes here
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = n-2; i >= 0; i--) {
        while(a[i] >= a[i+1]){
            ans++;
            a[i] /= 2;
            if(a[i] == 0) break;
        }
        if (a[i+1] == a[i])
        {
            ans = -1;
            break;
        }
    }
    cout << ans << endl;
    
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