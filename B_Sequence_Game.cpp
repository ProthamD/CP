#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

void solve(){
    //my codes here
    int m;
    cin >> m;
    vector<long long> b(m);
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    vector<long long> a;
    int j = 0;
    a.push_back(b[0]);
    for(int i = 1; i < m; i++) {
        if(a[j] <= b[i]){
            j++;
            a.push_back(b[i]);
        }#pragma region 
        else{
            j += 2;
            a.push_back(1);
            a.push_back(b[i]);
        }
    }
    cout << a.size() << endl;
    for(auto& it : a) {
        cout << it << " ";
    }
    cout << endl;

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