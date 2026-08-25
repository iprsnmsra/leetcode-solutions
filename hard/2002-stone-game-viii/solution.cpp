#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = stones.size();
        int current_prefix = 0;
        for (int stone : stones) {
            current_prefix += stone;
        }
        int max_diff = current_prefix;

        for (int i = n - 2; i >= 1; --i) {
            current_prefix -= stones[i + 1];
            max_diff = max(max_diff, current_prefix - max_diff);
        }

        return max_diff;
    }
};