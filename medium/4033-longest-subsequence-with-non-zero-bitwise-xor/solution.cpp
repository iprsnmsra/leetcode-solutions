class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int total_xor = 0;
        bool has_nonzero = false;
        for (const int& num : nums) {
            total_xor ^= num;              
            has_nonzero |= (num != 0);      
        }
        if (!has_nonzero) {
            return 0;
        }
        if (total_xor != 0) {
            return nums.size();
        }
        return nums.size() - 1;
    }
};