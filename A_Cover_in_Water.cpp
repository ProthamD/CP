#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<string>
using namespace std;

void solve(){
    //my codes here
    int n;
    cin >> n;
    string s = "";
    int cnt = 0;
    int total = 0;
    int maxi = 0;
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        s += c;
        if(c == '.'){
            cnt++;
            total++;
        }
        maxi = max(maxi, cnt);
        if(c == '#'){
            cnt = 0;
        }
    }
    if(maxi >= 3){
        cout << 2 << endl;
    }
    else{
        cout << total << endl;
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