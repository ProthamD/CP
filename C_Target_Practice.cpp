#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

void solve() {
    vector<vector<char>> a(10, vector<char>(10));
    int total = 0; // Initialize total points

    // Input 10x10 grid of chars
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(a[i][j] == 'X') {
                int d = min({i, j, 9-i, 9-j}); // Distance from the edges
                total += (d + 1); // Add points based on the ring
            }
        }
    }

    cout << total << endl;
    return;
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