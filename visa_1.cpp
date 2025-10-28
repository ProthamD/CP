#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        // Write your code here
        priority_queue<int, vector<int>, less<int>> pq;
        for (int num : arr) {
            pq.push(num);
        }
        int score = 0;
        while(!pq.empty() && k > 0) {
            int u = pq.top();
            pq.pop();
            score += u;
            u = ceil(u / 3.0);
            pq.push(u);
            k--;
        }


        return score;
    }
};

int main() {
    Solution sol;
    // Example usage:
    vector<int> arr = {10, 8, 6, 4, 2};
    int k = 4;
    cout << sol.maxScore(arr, k) << endl; // Expected Output: 11
    return 0;
}