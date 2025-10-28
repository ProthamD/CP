#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;


void solve(){
    //my codes here
    long long n, k , x;
    cin >> n >>  k >> x;
    long long minsum = k*(k+1)/2;
    long long maxsum = (2*n - k + 1)*k/2;
    if(x >= minsum && x <= maxsum) {
        cout << "YES" << endl;
    } else {
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