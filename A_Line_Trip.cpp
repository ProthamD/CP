#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

void solve(){
    //my codes here
    int n, x;
    cin >> n >> x;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int temp;
    int maxi = a[0];
    for(int i = 1 ; i <= n-1; i ++ ){
        temp = a[i] - a[i-1];
        maxi = max(maxi, temp);
    }
    int nextdist = 2* (x - a[n-1]);
    maxi = max(maxi, nextdist);
    cout << maxi << endl;
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