class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        uint64_t seen_once = 0;
        uint64_t seen_multiple = 0;

        for (int i = 0; i <= n - k; ++i) {
            uint64_t current_mask = 0;
            for (int j = i; j < i + k; ++j) {
                current_mask |= (1ULL << nums[j]);
            }
            
            uint64_t appearing_first_time = current_mask & ~(seen_once | seen_multiple);
            uint64_t appearing_second_time = current_mask & seen_once;
            seen_once = (seen_once & ~appearing_second_time) | appearing_first_time;
            seen_multiple |= appearing_second_time;
        }
        if (seen_once == 0) {
            return -1;
        }
        return 63 - __builtin_clzll(seen_once);
    }
};