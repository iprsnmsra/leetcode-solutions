#include <vector>
#include <deque>
#include <iostream>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        long long total_valid_subarrays = 0;
        int l = 0;

        deque<int> max_dq;
        deque<int> min_dq;

        for (int r = 0; r < n; ++r) {

            while (!max_dq.empty() && nums[max_dq.back()] <= nums[r]) {
                max_dq.pop_back();
            }
            max_dq.push_back(r);
            
            while (!min_dq.empty() && nums[min_dq.back()] >= nums[r]) {
                min_dq.pop_back();
            }
            min_dq.push_back(r);
            while (l <= r) {
                long long current_max = nums[max_dq.front()];
                long long current_min = nums[min_dq.front()];
                
                long long cost = (current_max - current_min) * (r - l + 1);
                
                if (cost > k) {
                    if (max_dq.front() == l) max_dq.pop_front();
                    if (min_dq.front() == l) min_dq.pop_front();
                    
                    l++; 
                } else {

                    break;
                }
            }
            total_valid_subarrays += (r - l + 1);
        }

        return total_valid_subarrays;
    }
};