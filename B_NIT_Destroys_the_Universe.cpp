#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

void solve(){
    //my codes here
    long long n;
    cin >> n;
    vector<long long> a(n);

    for(long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) cnt++;
    }
    bool found_zero = false;
    int left = 0, right = n - 1;
    while(a[left] == 0) left++;
    while(a[right] == 0) right--;
    for(int i = left; i <= right; i++) {
        if(a[i] == 0) found_zero = true;
    }
    if(cnt == n) {
        cout << 0 << endl;
    } else if(found_zero) {
        cout << 2 << endl;
    } else {
        cout << 1 << endl;
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