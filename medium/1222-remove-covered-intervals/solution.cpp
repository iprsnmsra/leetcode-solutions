class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });

        int valid_count = 0;
        int max_end = -1;
        for (const auto& interval : intervals) {
            if (interval[1] > max_end) {
                valid_count++;
                max_end = interval[1];
            }

        }

        return valid_count;
    }
};