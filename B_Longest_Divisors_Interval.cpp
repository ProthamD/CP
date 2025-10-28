#include <iostream>

void solve() {
    long long n;
    std::cin >> n;

    // Handle the edge case of n = 1.
    if (n == 1) {
        std::cout << 1 << std::endl;
        return;
    }
    
    long long count = 0;
   
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            count++;
        } else {

            break;
        }
    }
    std::cout << count << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}