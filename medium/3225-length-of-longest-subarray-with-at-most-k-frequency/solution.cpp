class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        vector<int> domain = nums;
        sort(domain.begin(), domain.end());
        domain.erase(unique(domain.begin(), domain.end()), domain.end());
        vector<int> compressed(n);
        for (int i = 0; i < n; ++i) {
            compressed[i] = lower_bound(domain.begin(), domain.end(), nums[i]) - domain.begin();
        }
        vector<int> freq(domain.size(), 0);
        
        int max_len = 0;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            int current_idx = compressed[right];
            freq[current_idx]++;
            while (freq[current_idx] > k) {
                freq[compressed[left]]--;
                left++;
            }
            int current_len = right - left + 1;
            if (current_len > max_len) {
                max_len = current_len;
            }
        }
        
        return max_len;
    }
};