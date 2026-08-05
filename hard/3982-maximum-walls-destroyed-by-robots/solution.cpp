#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
struct Robot {
    int pos;
    int dist;
    bool operator<(const Robot& other) const {
        return pos < other.pos;
    }
};

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = robots.size();
        vector<Robot> robs(n);
        for (int i = 0; i < n; ++i) {
            robs[i] = {robots[i], distance[i]};
        }
        sort(robs.begin(), robs.end());
        sort(walls.begin(), walls.end());
        int base_destroyed = 0;
        vector<int> filtered_walls;
        int r_idx = 0;
        
        for (int w : walls) {
            while (r_idx < n && robs[r_idx].pos < w) {
                r_idx++;
            }
            if (r_idx < n && robs[r_idx].pos == w) {
                base_destroyed++; 
            } else {
                filtered_walls.push_back(w);
            }
        }
        auto count_walls = [&](int L, int R) -> int {
            if (L > R) return 0;
            auto it1 = lower_bound(filtered_walls.begin(), filtered_walls.end(), L);
            auto it2 = upper_bound(filtered_walls.begin(), filtered_walls.end(), R);
            return it2 - it1; 
        };
        int dp_L = count_walls(robs[0].pos - robs[0].dist, robs[0].pos);
        int dp_R = 0;
        for (int i = 0; i < n - 1; ++i) {
            int P1 = robs[i].pos;
            int P2 = min(robs[i+1].pos, robs[i].pos + robs[i].dist);
            int P3 = max(robs[i].pos, robs[i+1].pos - robs[i+1].dist);
            int P4 = robs[i+1].pos;
            int C_R = count_walls(P1, P2);
            int C_L = count_walls(P3, P4);
            
            int C_union = 0;
            if (P2 < P3) {
                C_union = C_R + C_L; 
            } else {
                C_union = count_walls(P1, P4); 
            }
            int next_dp_L = max(dp_L + C_L, dp_R + C_union);
            int next_dp_R = max(dp_L + 0, dp_R + C_R);
            dp_L = next_dp_L;
            dp_R = next_dp_R;
        }
        dp_R += count_walls(robs[n-1].pos, robs[n-1].pos + robs[n-1].dist);

        return base_destroyed + max(dp_L, dp_R);
    }
};