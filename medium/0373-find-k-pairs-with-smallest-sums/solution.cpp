#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<vector<int>> result;
        result.reserve(k);

        int n = nums1.size();
        int m = nums2.size();
        auto comp = [&nums1, &nums2](const pair<int, int>& a, const pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> minHeap(comp);
        int limit = min(n, k);
        for (int i = 0; i < limit; ++i) {
            minHeap.push({i, 0});
        }
        while (k > 0 && !minHeap.empty()) {
            auto [i, j] = minHeap.top();
            minHeap.pop();
            result.push_back({nums1[i], nums2[j]});
            if (j + 1 < m) {
                minHeap.push({i, j + 1});
            }
            
            k--;
        }

        return result;
    }
};