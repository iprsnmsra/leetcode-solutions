class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if (nums.size() < 3) {
            return -1;
        }
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];
        int local_max = max({a, b, c});
        int local_min = min({a, b, c});
        if (a != local_max && a != local_min) return a;
        if (b != local_max && b != local_min) return b;
        
        return c;
    }
};