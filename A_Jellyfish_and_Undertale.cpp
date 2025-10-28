#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

void solve(){
    //my codes here
    int a, b , n;
    cin >> a >> b >> n;
    vector<int> x(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    long long totTime = b;
    for(int i = 0; i < n; i++) {
        long long curval = x[i];
        //maxm possible extra time
        long long addedtime = min(x[i],a-1);
        totTime += addedtime;
    }

    cout << totTime << endl;
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