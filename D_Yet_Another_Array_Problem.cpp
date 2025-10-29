#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin>>n;
        vector<ll>a(n);
          for(ll i=0;i<n;i++){
              cin>>a[i];
          }
 
          ll ans=-1;
          for(ll  x=2;x<=100;x++){
             for(ll val:a){
              if (__gcd(val, x) == 1) {
                    ans = x;
                    break;
                }
             }
             if(ans!=-1) break;
          }
       
 
        if (ans == -1) cout << -1 << endl;
        else cout << ans << endl;
    }
}