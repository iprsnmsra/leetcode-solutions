#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        vector<int> freq(2 * n + 2, 0);
        int offset = n; 
        freq[offset] = 1; 
        
        int current_sum = 0;
        int valid_past_sums = 0; 
        int total_subarrays = 0;
        
        for (int num : nums) {
            if (num == target) {
                valid_past_sums += freq[current_sum + offset];
                current_sum++;
            } else {
                valid_past_sums -= freq[current_sum - 1 + offset];
                current_sum--;
            }
            total_subarrays += valid_past_sums;
            freq[current_sum + offset]++;
        }
        
        return total_subarrays;
    }
};