#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        vector<pair<int, int>> val_idx(n);
        for (int i = 0; i < n; ++i) {
            val_idx[i] = {nums[i], i};
        }
        sort(val_idx.begin(), val_idx.end());

        vector<int> result(n);
        int i = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && val_idx[j].first - val_idx[j - 1].first <= limit) {
                j++;
            }
            vector<int> indices;
            indices.reserve(j - i); 
            for (int k = i; k < j; ++k) {
                indices.push_back(val_idx[k].second);
            }
            sort(indices.begin(), indices.end());
            for (int k = i; k < j; ++k) {
                result[indices[k - i]] = val_idx[k].first;
            }
            i = j;
        }

        return result;
    }
};