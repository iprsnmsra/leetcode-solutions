#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        double max_area = 0.0;
        int n = points.size();
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    double area = 0.5 * abs(
                        points[i][0] * (points[j][1] - points[k][1]) +
                        points[j][0] * (points[k][1] - points[i][1]) +
                        points[k][0] * (points[i][1] - points[j][1])
                    );
                    max_area = max(max_area, area);
                }
            }
        }

        return max_area;
    }
};