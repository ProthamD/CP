#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<cmath>
using namespace std;

void solve(){
    //my codes here
    long long n;
    cin >> n;
    long long min = 0;
    long long max = 0;
    if(n < 4 || n % 2 == 1){
        cout << -1 << endl;
        return;
    }
    else{
        min = ((n+5)/ 6);

        max = n / 4;
        if(min == 0) min = max;
        cout << min << " " << max << endl;
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