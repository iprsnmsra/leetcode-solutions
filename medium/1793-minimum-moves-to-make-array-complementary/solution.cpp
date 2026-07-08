#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();

        vector<int> delta(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; ++i) {
            int A = min(nums[i], nums[n - 1 - i]);
            int B = max(nums[i], nums[n - 1 - i]);

            delta[2] += 2;

            delta[1 + A] -= 1;

            delta[A + B] -= 1;

            delta[A + B + 1] += 1;

            delta[B + limit + 1] += 1;
        }

        int min_moves = n; 
        int current_moves = 0;


        for (int T = 2; T <= 2 * limit; ++T) {
            current_moves += delta[T];
            min_moves = min(min_moves, current_moves);
        }

        return min_moves;
    }
};