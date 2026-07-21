#include <vector>
#include <unordered_map>
#include <numeric>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        vector<long long> result(n, 0);

        unordered_map<int, vector<int>> index_groups;
        
        for (int i = 0; i < n; ++i) {
            index_groups[nums[i]].push_back(i);
        }

        for (auto& [value, indices] : index_groups) {
            
            long long right_sum = 0;
            long long left_sum = 0;

            for (int idx : indices) {
                right_sum += idx;
            }
            
            long long right_count = indices.size();
            long long left_count = 0;

            for (int current_idx : indices) {

                right_sum -= current_idx;
                right_count -= 1;

                long long left_distance = (left_count * current_idx) - left_sum;
                long long right_distance = right_sum - (right_count * current_idx);
                
                result[current_idx] = left_distance + right_distance;

                left_sum += current_idx;
                left_count += 1;
            }
        }

        return result;
    }
};