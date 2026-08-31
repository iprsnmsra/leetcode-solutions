#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int waysToSplit(vector<int>& nums) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        long long MOD = 1e9 + 7;
        for (int i = 1; i < n; ++i) {
            nums[i] += nums[i - 1];
        }

        int totalSum = nums[n - 1];
        long long count = 0;
        int k = 0, m = 0;
        for (int i = 0; i < n - 2; ++i) {
            if (k <= i) k = i + 1;
            while (k < n - 1 && nums[k] < 2 * nums[i]) {
                k++;
            }

            if (m < k) m = k;
            while (m < n - 1 && 2 * nums[m] <= totalSum + nums[i]) {
                m++;
            }
            if (m > k) {
                count = (count + (m - k)) % MOD;
            }
        }

        return count;
    }
};