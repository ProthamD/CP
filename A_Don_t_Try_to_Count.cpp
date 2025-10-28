#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

int f(string x, string s, int& cnt, int call){
    int n = x.size();
    int m = s.size();
    bool found = (x.find(s) != string::npos);
    if(!found){
        if(n <= m  || call <= 1){
            x = x + x;
            cnt++;
            call++;
            f(x,s,cnt, call);
        }
        else{
            cnt = -1;
            return cnt;
        }
    }
    else if(found == true){
        return cnt;
    } 
    return -1;
}

void solve(){
    //my codes here
    int n, m;
    cin >> n >> m;
    string x= "";
    for(int i=0;i<n;i++){
        char c;
        cin >> c;
        x += c;
    }
    string s = "";
    for(int i=0;i<m;i++){
        char c1;
        cin >> c1;
        s += c1;
    }
    int cnt = 0;
    int call = 0;
    f(x,s,cnt, call);
    cout << cnt << endl;;


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