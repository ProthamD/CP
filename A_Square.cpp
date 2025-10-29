#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

void solve(){
    //my codes here
    vector<int> arr(4);
    for(int i = 0; i < 4; i++) {
        cin >> arr[i];
    }
    int same = arr[0];
    for(int i = 1; i < 4; i++) {
        if(arr[i] != same) {
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