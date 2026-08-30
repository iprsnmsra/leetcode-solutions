class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        if (n <= 2) return n;

        int min_idx = 0;
        int max_idx = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[min_idx]) min_idx = i;
            if (nums[i] > nums[max_idx]) max_idx = i;
        }
        int left = min(min_idx, max_idx);
        int right = max(min_idx, max_idx);
        int front_sweep = right + 1;               
        int back_sweep = n - left;                 
        int pincer_attack = (left + 1) + (n - right); 
        return min({front_sweep, back_sweep, pincer_attack});
    }
};