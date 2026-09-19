class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = points.size();
        if (n <= 2) return n;

        int max_points = 1;
        vector<uint64_t> slopes;
        slopes.reserve(n);

        for (int i = 0; i < n; ++i) {
            slopes.clear();

            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                if (dx == 0) {
                    dy = 1; // Standardize vertical lines
                } else if (dy == 0) {
                    dx = 1; // Standardize horizontal lines
                } else {
                    if (dx < 0) {
                        dx = -dx;
                        dy = -dy;
                    }
                    int g = std::gcd(abs(dx), abs(dy));
                    dx /= g;
                    dy /= g;
                }
                uint64_t key = ((uint64_t)(uint32_t)dx << 32) | (uint32_t)dy;
                slopes.push_back(key);
            }
            if (!slopes.empty()) {
                sort(slopes.begin(), slopes.end());
                
                int current_max = 1;
                int current_streak = 1;
                
                for (size_t k = 1; k < slopes.size(); ++k) {
                    if (slopes[k] == slopes[k - 1]) {
                        current_streak++;
                    } else {
                        current_max = max(current_max, current_streak);
                        current_streak = 1;
                    }
                }
                current_max = max(current_max, current_streak);
                max_points = max(max_points, current_max + 1);
            }
        }

        return max_points;
    }
};