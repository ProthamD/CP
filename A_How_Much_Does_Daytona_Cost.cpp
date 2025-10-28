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
  
    for(int i = 0 ; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        if(a[i] == k){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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