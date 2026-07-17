#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        if (n == 0) return 0;

        long long sum = 0;
        long long current_F = 0;

        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            current_F += (long long)i * nums[i];
        }

        long long max_F = current_F;

        for (int i = n - 1; i >= 1; --i) {
            current_F = current_F + sum - ((long long)n * nums[i]);
            
            if (current_F > max_F) {
                max_F = current_F;
            }
        }

        return max_F;
    }
};