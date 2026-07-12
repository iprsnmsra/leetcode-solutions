#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<pair<int, int>> sorted_nums(n);
        for (int i = 0; i < n; ++i) {
            sorted_nums[i] = {nums[i], i};
        }
        sort(sorted_nums.begin(), sorted_nums.end());
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[sorted_nums[i].second] = i;
        }
        vector<int> comp(n, 0);
        int current_id = 0;
        for (int i = 1; i < n; ++i) {
            if (sorted_nums[i].first - sorted_nums[i - 1].first > maxDiff) {
                current_id++;
            }
            comp[i] = current_id;
        }
        int LOG = 18; // 2^17 is ~131,000, which safely covers N <= 100,000
        vector<vector<int>> R(LOG, vector<int>(n, 0));
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (j + 1 < n && sorted_nums[j + 1].first - sorted_nums[i].first <= maxDiff) {
                j++;
            }
            R[0][i] = j;
        }
        for (int k = 1; k < LOG; ++k) {
            for (int i = 0; i < n; ++i) {
                R[k][i] = R[k - 1][R[k - 1][i]];
            }
        }
        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int u = q[0];
            int v = q[1];
            if (u == v) {
                ans.push_back(0);
                continue;
            }

            int x = pos[u];
            int y = pos[v];
            if (x > y) swap(x, y);
            if (comp[x] != comp[y]) {
                ans.push_back(-1);
                continue;
            }
            int curr = x;
            int steps = 0;

            for (int k = LOG - 1; k >= 0; --k) {
                if (R[k][curr] < y) {
                    curr = R[k][curr];
                    steps += (1 << k); 
                }
            }
            ans.push_back(steps + 1);
        }

        return ans;
    }
};