#include <iostream>
#include <vector>

using namespace std;


vector<long long> precomputeCosts(int maxPower) {
    vector<long long> costs(maxPower + 1, 0);
    costs[0] = 3; 
    for (int i = 1; i <= maxPower; i++) {

        long long cost = 1;
    
        for (int j = 0; j < i+1; j++) cost *= 3;
        long long part2 = 1;
      
        for (int j = 0; j < i-1; j++) part2 *= 3;
        cost += i * part2;
        costs[i] = cost;
    }
    return costs;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    
    int maxPower = 20;
    vector<long long> costs = precomputeCosts(maxPower);

    while (t--) {
        long long n;
        cin >> n;

        long long totalCost = 0;

        int power = 0;
        while (n > 0) {
            int digit = n % 3;  // base 3 digit
            totalCost += digit * costs[power];
            n /= 3;
            power++;
        }

        cout << totalCost << "\n";
    }

    return 0;
}
