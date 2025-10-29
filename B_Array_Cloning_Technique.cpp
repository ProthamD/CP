#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<unordered_map>
using namespace std;

void solve(){
    //my codes here
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    unordered_map<int, int> freq;
    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    int cur_frq = 0;
    for(auto it : freq) {
        cur_frq = max(cur_frq, it.second);
    }
    int operation = 0;
    while(cur_frq < n) {
        operation++;
        if(cur_frq * 2 <= n) {
            operation += cur_frq;
            cur_frq *= 2;
        } else {
            operation += n - cur_frq;
            cur_frq = n;
        }
    }
    cout << operation << endl;
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