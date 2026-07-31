#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        vector<vector<int>> pos_map(n + 1);

        for (int i = 0; i < n; ++i) {
            pos_map[nums[i]].push_back(i);
        }

        long long min_dist = LLONG_MAX;
        bool found = false;
        for (int v = 1; v <= n; ++v) {
            const vector<int>& indices = pos_map[v];
            if (indices.size() >= 3) {
                found = true;
                for (int i = 0; i <= (int)indices.size() - 3; ++i) {
                    long long current_dist = 2LL * (indices[i + 2] - indices[i]);
                    if (current_dist < min_dist) {
                        min_dist = current_dist;
                    }
                }
            }
        }

        return found ? (int)min_dist : -1;
    }
};