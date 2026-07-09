#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> component(n, 0);
        int current_id = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                current_id++;
            }
            component[i] = current_id;
        }
        vector<bool> ans;
        ans.reserve(queries.size()); 

        for (const auto& q : queries) {
            ans.push_back(component[q[0]] == component[q[1]]);
        }

        return ans;
    }
};