#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
struct Square {
    int left;
    int right;
    int height;
};

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<Square> landed;
        vector<int> result;
        int current_max_h = 0;

        for (auto& pos : positions) {
            int L = pos[0];
            int side = pos[1];
            int R = L + side;
            
            int base_h = 0;

            for (const auto& prev : landed) {
                if (L < prev.right && prev.left < R) {
                    base_h = max(base_h, prev.height);
                }
            }

            int new_h = base_h + side;
            landed.push_back({L, R, new_h});
            current_max_h = max(current_max_h, new_h);
            result.push_back(current_max_h);
        }

        return result;
    }
};