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
    long long mini = LLONG_MAX;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
   }

   for(int i = 0; i < n; i++) {
        mini = min(mini, abs(a[i]));
   }
   cout << mini << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    


    solve();
    
    
    return 0;
}