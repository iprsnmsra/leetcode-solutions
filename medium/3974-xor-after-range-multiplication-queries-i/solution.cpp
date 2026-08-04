#include <vector>

using namespace std;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long long MOD = 1e9 + 7;
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            long long v = q[3]; 
            for (int idx = l; idx <= r; idx += k) {
                nums[idx] = (nums[idx] * v) % MOD;
            }
        }
        int final_xor = 0;
        for (int num : nums) {
            final_xor ^= num;
        }
        
        return final_xor;
    }
};