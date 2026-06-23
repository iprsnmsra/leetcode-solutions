#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int num_intervals = intervals.size();
        int num_queries = queries.size();

        vector<pair<int, int>> sorted_queries(num_queries);
        for (int i = 0; i < num_queries; ++i) {
            sorted_queries[i] = {queries[i], i};
        }

        sort(intervals.begin(), intervals.end());
        sort(sorted_queries.begin(), sorted_queries.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        
        vector<int> ans(num_queries);
        int interval_idx = 0;

        for (const auto& [q_val, q_idx] : sorted_queries) {

            while (interval_idx < num_intervals && intervals[interval_idx][0] <= q_val) {
                int left = intervals[interval_idx][0];
                int right = intervals[interval_idx][1];
                int size = right - left + 1;
                
                min_heap.push({size, right});
                interval_idx++;
            }

            while (!min_heap.empty() && min_heap.top().second < q_val) {
                min_heap.pop();
            }

            if (!min_heap.empty()) {
                ans[q_idx] = min_heap.top().first;
            } else {
                ans[q_idx] = -1; 
            }
        }

        return ans;
    }
};