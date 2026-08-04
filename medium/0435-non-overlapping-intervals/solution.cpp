#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int removed_count = 0;
        int prev_end = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < prev_end) {
                removed_count++;
            } else {
                prev_end = intervals[i][1];
            }
        }

        return removed_count;
    }
};