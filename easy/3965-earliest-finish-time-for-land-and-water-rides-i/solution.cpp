#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int min_finish_time = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {

                int land_first_end = landStartTime[i] + landDuration[i];

                int water_second_start = max(land_first_end, waterStartTime[j]);
                int finish_route_a = water_second_start + waterDuration[j];

                int water_first_end = waterStartTime[j] + waterDuration[j];

                int land_second_start = max(water_first_end, landStartTime[i]);
                int finish_route_b = land_second_start + landDuration[i];

                min_finish_time = min({min_finish_time, finish_route_a, finish_route_b});
            }
        }

        return min_finish_time;
    }
};