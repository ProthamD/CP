#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;



void solve(){
    //my codes here
    int n;
    cin >> n;
    int mini =  INT_MAX;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mini = min(mini, a[i]);
    }

    if(a[0] == mini ) {
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