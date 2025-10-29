#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

void solve(){
    //my codes here
    int a, b , c;
    cin >> a >> b >> c;
    if(a == b && c % 2 == 1){
        cout << "First" << endl;
    }
    else if(a == b && c % 2 == 0){
        cout << "Second" << endl;
    }
    else if(a != b){
        cout << (min(a, b) == b ? "First" : "Second") << endl;
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