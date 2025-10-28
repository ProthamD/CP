#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxProducts(vector<int>& prices, vector<pair<int, int>>& queries) {
        // Implement your logic here
        // prices: array of prices in non-decreasing order
        // queries: each pair is (pos, amount)
        // Return a vector with the answer for each query
        vector<int> result;
        int n = prices.size();
        for (const auto& query : queries) {
            int i = query.first-1;
            int amount = query.second;
            int count = 0;
            while(i <= n-1 && prices[i] <= amount) {
                count++;
                amount -= prices[i];
                i++;
            }
            result.push_back(count);
        }
        return result;
    }
};

int main() {
    Solution sol;
    // Sample input
    vector<int> prices = {2, 3, 5, 8, 13};
    vector<pair<int, int>> queries = {{2, 9}, {1, 15}, {4, 8}};
    vector<int> res = sol.maxProducts(prices, queries);
    for (int ans : res) cout << ans << endl;
    // Expected output for the above input:
    // 2
    // 3
    // 1
    return 0;
}