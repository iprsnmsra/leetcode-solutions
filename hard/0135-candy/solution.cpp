#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = ratings.size();
        if (n == 0) return 0;

        int total_candies = 1;
        int up = 0;
        int down = 0;
        int peak = 0;

        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                up++;
                peak = up;
                down = 0;
                total_candies += 1 + up;
                
            } else if (ratings[i] == ratings[i - 1]) {
                up = 0;
                down = 0;
                peak = 0;
                total_candies += 1;
                
            } else {
                up = 0;
                down++;
                total_candies += down;
                if (down > peak) {
                    total_candies++;
                }
            }
        }

        return total_candies;
    }
};