class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            int digit_sum = (val % 10) + ((val / 10) % 10) + ((val / 100) % 10) + (val / 1000);
            if (digit_sum == i) {
                return i;
            }
        }

        return -1;
    }
};