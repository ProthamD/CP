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
    unordered_map<int,int> freq;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        freq[x]++;
    }
    for(auto it : freq){
        if(it.second >= 2){
            cout << "YES" << endl;
            return;
        }

    }
    cout << "NO" << endl;


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