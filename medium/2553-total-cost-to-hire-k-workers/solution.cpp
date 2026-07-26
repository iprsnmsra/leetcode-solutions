#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        
        int i = 0;
        int j = n - 1;
        long long ans = 0;

        while (k--) {

            while (pq1.size() < candidates && i <= j) {
                pq1.push(costs[i++]);
            }
            while (pq2.size() < candidates && i <= j) {
                pq2.push(costs[j--]);
            }

            int t1 = !pq1.empty() ? pq1.top() : 1e9;
            int t2 = !pq2.empty() ? pq2.top() : 1e9;
            if (t1 <= t2) {
                ans += t1;
                pq1.pop();
            } else {
                ans += t2;
                pq2.pop();
            }
        }

        return ans;
    }
};