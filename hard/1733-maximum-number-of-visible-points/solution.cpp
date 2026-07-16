#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int loc_x = location[0];
        int loc_y = location[1];
        int same_location_count = 0;
        
        vector<double> angles;
        for (const auto& p : points) {
            if (p[0] == loc_x && p[1] == loc_y) {
                same_location_count++;
            } else {
                double a = atan2(p[1] - loc_y, p[0] - loc_x) * 180.0 / M_PI;
                angles.push_back(a);
            }
        }

        sort(angles.begin(), angles.end());
        int n = angles.size();
        for (int i = 0; i < n; ++i) {
            angles.push_back(angles[i] + 360.0);
        }
        
        int max_visible = 0;
        int left = 0;

        for (int right = 0; right < angles.size(); ++right) {
            while (angles[right] - angles[left] > angle) {
                left++;
            }
            max_visible = max(max_visible, right - left + 1);
        }
        
        return max_visible + same_location_count;
    }
};