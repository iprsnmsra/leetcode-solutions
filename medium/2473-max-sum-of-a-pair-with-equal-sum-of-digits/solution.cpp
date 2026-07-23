#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int max_seen[82] = {0}; 
        int global_max_sum = -1;

        for (int num : nums) {
            int d_sum = 0;
            int temp = num;

            while (temp > 0) {
                d_sum += temp % 10;
                temp /= 10;
            }
            if (max_seen[d_sum] > 0) {
                int current_pair_sum = num + max_seen[d_sum];
                if (current_pair_sum > global_max_sum) {
                    global_max_sum = current_pair_sum;
                }
            }
            if (num > max_seen[d_sum]) {
                max_seen[d_sum] = num;
            }
        }

        return global_max_sum;
    }
};