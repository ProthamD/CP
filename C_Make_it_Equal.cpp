#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<map>
using namespace std;

void solve(){
    //my codes here
    int n, k;
    cin >> n >> k;
    map<int,int> mpp;

    for(int i=0; i < n; ++i) {
        int x;
        cin >> x;
        mpp[x % k]++;
        mpp[k-x % k]++;
    }
    for(int i=0; i < n; ++i) {
        int y;
        cin >> y;
        mpp[y % k]--;
        mpp[k-y % k]--;
    }
    for(auto it : mpp) {
        if(it.second != 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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