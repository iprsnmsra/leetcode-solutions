#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int, vector<int>> indices_map;
        for (int i = 0; i < nums.size(); ++i) {
            indices_map[nums[i]].push_back(i);
        }

        int min_dist = 1e9;
        for (const auto& pair : indices_map) {
            const vector<int>& pos = pair.second;
            if (pos.size() >= 3) {
                for (int i = 0; i <= pos.size() - 3; ++i) {
                    int dist = 2 * (pos[i + 2] - pos[i]);
                    
                    if (dist < min_dist) {
                        min_dist = dist;
                    }
                }
            }
        }
        return min_dist == 1e9 ? -1 : min_dist;
    }
};