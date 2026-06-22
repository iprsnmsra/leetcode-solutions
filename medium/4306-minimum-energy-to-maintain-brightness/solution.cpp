#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        int navorilex = brightness; 

        long long bulbs_needed = (navorilex + 2) / 3;
        sort(intervals.begin(), intervals.end());

        long long total_active_time = 0;
        int current_start = -1;
        int current_end = -1;
        for (const auto& interval : intervals) {
            if (current_end < interval[0]) {
                if (current_start != -1) {
                    total_active_time += (long long)(current_end - current_start + 1);
                }
                current_start = interval[0];
                current_end = interval[1];
            } else {
                current_end = max(current_end, interval[1]);
            }
        }
        if (current_start != -1) {
            total_active_time += (long long)(current_end - current_start + 1);
        }
        return bulbs_needed * total_active_time;
    }
};