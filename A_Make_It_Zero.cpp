#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

void solve(){
    //my codes here
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if(n % 2 == 0){
        cout << 2 << endl;
        cout << 1 << " " << n << endl;
        cout << 1 << " " << n << endl;
    }
    else{//odd always will have 4 solutions, first and second operation from 1 to n-1, thirs and 4 th operation from n-1 to n

        cout << 4 << endl;
        cout << 1 << " " << n-1 << endl;
        cout << 1 << " " << n-1 << endl;
        cout << n-1 << " " << n << endl;
        cout << n-1 << " " << n << endl;
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