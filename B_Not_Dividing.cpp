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
    for(int i = 0; i < n; i++) {
        if(a[i] == 1) {
            a[i]++;
        }
    }
    for(int i = 0; i < n-1; i++) {
        if(a[i+1] % a[i] == 0) {
            a[i+1]++;
        }
    }
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
        cout << endl;
    }
    
    return 0;
}