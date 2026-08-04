class Solution {

    int memo[21][21];

public:

    bool predictTheWinner(vector<int>& nums) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();

        for(int i=0; i<21; ++i) {
            for(int j=0; j<21; ++j) {
                memo[i][j] = -1e9;
            }
        }

        return maxDiff(nums, 0, n - 1) >= 0;
    }

private:
    int maxDiff(const vector<int>& nums, int left, int right) {
    
        if (left == right) {
            return nums[left];
        }

 
        if (memo[left][right] != -1e9) {
            return memo[left][right];
        }

        int pickLeft = nums[left] - maxDiff(nums, left + 1, right);


        int pickRight = nums[right] - maxDiff(nums, left, right - 1);

        return memo[left][right] = max(pickLeft, pickRight);
    }
};