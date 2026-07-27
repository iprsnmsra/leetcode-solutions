#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
    vector<vector<long long>> memo;

    long long dfs(int r, int f, const vector<int>& robot, const vector<int>& flat_factories) {
        // Base Case 1: All robots successfully repaired
        if (r == robot.size()) {
            return 0;
        }
        
        // Base Case 2: Ran out of factories before repairing all robots
        if (f == flat_factories.size()) {
            // Return an arbitrarily large number (Infinity) that won't overflow when added to
            return 1000000000000000LL; 
        }

        // Return cached result
        if (memo[r][f] != -1) {
            return memo[r][f];
        }

        // Choice 1: Skip this specific factory slot
        long long skip = dfs(r, f + 1, robot, flat_factories);

        // Choice 2: Assign the current robot to this specific factory slot
        long long dist = abs((long long)robot[r] - flat_factories[f]);
        long long assign = dist + dfs(r + 1, f + 1, robot, flat_factories);

        // Cache and return the optimal path
        return memo[r][f] = min(skip, assign);
    }

public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // Optimization: Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // 1. Sort robots and factories by their physical positions
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        // 2. Flatten the factories array safely
        vector<int> flat_factories;
        for (const auto& fact : factory) {
            int pos = fact[0];
            int limit = fact[1];
            
            // THE FIX: Cap the limit per-factory, NOT globally!
            // No single factory will ever need to repair more than the total number of robots.
            int max_repairs = min(limit, (int)robot.size());
            
            for (int i = 0; i < max_repairs; ++i) {
                flat_factories.push_back(pos);
            }
        }

        // 3. Initialize memoization table
        memo.assign(robot.size(), vector<long long>(flat_factories.size(), -1));

        // 4. Start the Top-Down DP
        return dfs(0, 0, robot, flat_factories);
    }
};