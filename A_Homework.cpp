#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include<string>
using namespace std;

void solve(){
    //my codes here
    int n;
    cin >> n;
    string a = "";
    cin >> a;
    int m;
    cin  >> m;
    string b="";
    cin >> b;
    string c = "";
    cin >> c;
    for(int i = 0; i <= m-1 ; i++){
        if(c[i] == 'V'){
            a = b[i] + a;
        }
        else{
            a.push_back(b[i]);
        }
    }
    cout << a << endl;
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