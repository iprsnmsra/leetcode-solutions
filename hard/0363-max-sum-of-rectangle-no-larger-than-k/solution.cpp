#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int rows = matrix.size();
        int cols = matrix[0].size();
        int max_res = -1e9; 
        bool fix_cols = cols <= rows;
        int outer_bound = fix_cols ? cols : rows;
        int inner_bound = fix_cols ? rows : cols;
        for (int left = 0; left < outer_bound; ++left) {
            vector<int> row_sums(inner_bound, 0);
            
            for (int right = left; right < outer_bound; ++right) {
                for (int i = 0; i < inner_bound; ++i) {
                    row_sums[i] += fix_cols ? matrix[i][right] : matrix[right][i];
                }
                int kadane_curr = 0, kadane_max = -1e9;
                for (int val : row_sums) {
                    kadane_curr = max(val, kadane_curr + val);
                    kadane_max = max(kadane_max, kadane_curr);
                }
                if (kadane_max <= k) {
                    max_res = max(max_res, kadane_max);
                    if (max_res == k) return k; 
                    continue;
                }
                set<int> cum_set;
                cum_set.insert(0); 
                int curr_sum = 0;

                for (int sum : row_sums) {
                    curr_sum += sum;
                    auto it = cum_set.lower_bound(curr_sum - k);
                    
                    if (it != cum_set.end()) {
                        max_res = max(max_res, curr_sum - *it);
                    }
                    if (max_res == k) return k;
                    
                    cum_set.insert(curr_sum);
                }
            }
        }

        return max_res;
    }
};