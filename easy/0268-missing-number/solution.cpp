class Solution {
public:
    int missingNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int missing_state = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            missing_state ^= i ^ nums[i]; 
        }
        
        return missing_state;
    }
};