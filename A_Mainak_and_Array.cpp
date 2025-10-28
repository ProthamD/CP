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
    long long answer = a[n-1] - a[0];
    for(long long i = 1; i <= n-1; i++) {//all elements vs a[0]
        answer = max (answer, (long long)(a[i] - a[0]));
    }
    for(long long i = 0; i < n-1; i++) {//all elements vs a[n-1]
        answer = max (answer, (long long)(a[n-1] - a[i]));
    }
    for(long long i = 0; i <= n-2; i++) {//adjacent elements
        answer = max (answer, (long long)(a[i] - a[i+1]));
    }

    cout << answer << endl;
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