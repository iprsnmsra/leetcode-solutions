#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> counts(n + 1, 0);

        counts[0] = 1;
        
        int current_sum = 0;
        int total_nice = 0;
        
        for (int num : nums) {
            current_sum += (num & 1);

            if (current_sum >= k) {
                total_nice += counts[current_sum - k];
            }
            counts[current_sum]++;
        }
        
        return total_nice;
    }
};