#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

void solve(){
    //my codes here
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if(n == 0){
        cout << 0 << endl;
        return;
    }
    sort(a.begin(), a.end());
    int maxstreak = 1;
    int maxi = 1;
    for(int i = 1; i < n; i++){
        if(a[i] - a[i-1] <= k){
            maxstreak++;
        } else{
            maxstreak = 1;
        }
        maxi = max(maxi, maxstreak);
    }
    int res = n - maxi;
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