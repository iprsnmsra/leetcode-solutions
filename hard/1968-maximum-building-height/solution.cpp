#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});
        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();
        for (int i = 1; i < m; ++i) {
            int dist = restrictions[i][0] - restrictions[i - 1][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i - 1][1] + dist);
        }
        for (int i = m - 2; i >= 0; --i) {
            int dist = restrictions[i + 1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i + 1][1] + dist);
        }

        long long global_max_height = 0;
        for (int i = 0; i < m - 1; ++i) {
            long long h1 = restrictions[i][1];
            long long h2 = restrictions[i + 1][1];
            long long dist = restrictions[i + 1][0] - restrictions[i][0];
            long long local_peak = (h1 + h2 + dist) / 2;
            
            if (local_peak > global_max_height) {
                global_max_height = local_peak;
            }
        }

        return global_max_height;
    }
};