#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int counts[3] = {0, 0, 0};
        for (const int& stone : stones) {
            counts[stone % 3]++;
        }
        if (counts[0] % 2 == 0) {
            return counts[1] > 0 && counts[2] > 0;
        } else {
            return abs(counts[1] - counts[2]) > 2;
        }
    }
};