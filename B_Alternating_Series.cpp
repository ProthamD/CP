#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

void solve(){
    long n;
    cin >> n;
    vector<long long> a(n,-1);
    if(n % 2 != 0){
        for(int i = 0; i < n; ++i){
            if(i % 2 == 0){
                a[i] = -1;
            }
            else{
                a[i] = 3;
            }
        }
    }
    else{
        if(n == 2){
            a[0] = -1;
            a[1] = 2;
        }
        else{
            for(int i = 0; i < n-2; ++i){
                if(i % 2 == 0){
                    a[i] = -1;
                }
                else{
                    a[i] = 3;
                }
            }
            a[n-2] = -1;
            a[n-1] = 2;
        }
    }
    for(auto x : a) cout << x << " ";
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