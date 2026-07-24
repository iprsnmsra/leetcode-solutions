#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int prev2 = 0; 
        int prev1 = 0; 

        for (int i = 2; i <= cost.size(); ++i) {

            int cost_from_prev1 = prev1 + cost[i - 1];
            int cost_from_prev2 = prev2 + cost[i - 2];
            
            int current_cost = min(cost_from_prev1, cost_from_prev2);

            prev2 = prev1;
            prev1 = current_cost;
        }
        return prev1;
    }
};