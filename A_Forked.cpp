#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<set>
using namespace std;

int dx[4] = {-1, 1, -1, 1};
int dy[4] = {-1, -1, 1, 1};

void solve(){
    //my codes here
    int a, b;
    cin >> a >> b;
    int xk, yk;
    cin >> xk >> yk;
    int xq, yq;
    cin >> xq >> yq;
    set<pair<int, int>> k_hits, q_hits;
    for(int j = 0; j < 4; j++){
       k_hits.insert({xk + dx[j] *a, yk + dy[j] * b});
       k_hits.insert({xk + dx[j] *b, yk + dy[j] * a});
       q_hits.insert({xq + dx[j] *a, yq + dy[j] * b});
       q_hits.insert({xq + dx[j] *b, yq + dy[j] * a});    
    }

    int ans = 0; 
    for(auto it : k_hits) {
        if(q_hits.find(it) != q_hits.end()) {
            ans++;
        }
    }

    cout << ans << endl;

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