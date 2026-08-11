class Solution {
public:
    int missingInteger(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        uint64_t existence_mask = 0;
        
        int prefix_sum = nums[0];
        existence_mask |= (1ULL << nums[0]);
        bool is_sequential = true;
        for (int i = 1; i < nums.size(); ++i) {
            existence_mask |= (1ULL << nums[i]);
            
            if (is_sequential) {
                if (nums[i] == nums[i - 1] + 1) {
                    prefix_sum += nums[i];
                } else {
                    is_sequential = false; 
                }
            }
        }
        while (prefix_sum <= 50 && (existence_mask & (1ULL << prefix_sum))) {
            prefix_sum++;
        }

        return prefix_sum;
    }
};